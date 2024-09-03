


		// optimise pour calculer le meilleur value qui va dans la b (celui qui coute le moins cher)
// calcule la position target
// calcule le cout
// structure move des rotations


/* Pour implémenter l'algorithme décrit dans votre message, qui est appelé ici l'algorithme "Turk", voici comment vous pouvez procéder.
Cet algorithme consiste essentiellement à déplacer des éléments de STACK_A vers STACK_B dans l'ordre décroissant,
puis à les réinsérer dans STACK_A pour obtenir un tri croissant.

Je vais diviser l'implémentation en plusieurs fonctions pour respecter les contraintes de code et de lignes.
1. Trouver et déplacer le nombre minimal dans STACK_A à STACK_B

Vous avez déjà une fonction find_min et une fonction move_min_to_top.
Nous allons les utiliser pour pousser les éléments de STACK_A à STACK_B tout en maintenant l'ordre décroissant dans STACK_B.
2. Calculer le coût d'insertion d'un élément dans STACK_B

Nous avons besoin d'une fonction qui calcule le nombre d'opérations nécessaires pour insérer chaque élément de STACK_A dans STACK_B à la bonne position. */



#include "../push_swap.h"

int calculate_cost(t_stack *a, t_stack *b, int index)
{
	int cost_a;
	int cost_b;
	int target_pos_b;

	target_pos_b = find_position_in_b(b, a->data[index]); // Trouve la position d'insertion dans B
	cost_a = index <= a->size / 2 ? index : a->size - index;
	cost_b = target_pos_b <= b->size / 2 ? target_pos_b : b->size - target_pos_b;

	return (cost_a + cost_b);
}

/* 3. Trouver l'élément le moins coûteux à déplacer

Cette fonction parcourt STACK_A et utilise calculate_cost pour trouver l'élément qui est le moins coûteux à déplacer vers STACK_B.
 */

int find_cheapest_move(t_stack *a, t_stack *b)
{
	int i;
	int min_cost;
	int best_index;
	int current_cost;

	i = 0;
	min_cost = INT_MAX;
	best_index = 0;
	while (i < a->size)
	{
		current_cost = calculate_cost(a, b, i);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			best_index = i;
		}
		i++;
	}
	return (best_index);
}

/* 4. Effectuer le mouvement optimal

Cette fonction effectue le mouvement optimal en fonction du coût calculé. */


void execute_optimal_move(t_stack *a, t_stack *b)
{
	int best_index;
	int target_pos_b;

	best_index = find_cheapest_move(a, b);
	move_min_to_top(a, best_index); // Déplace l'élément à la meilleure position dans A
	target_pos_b = find_position_in_b(b, a->data[0]);
	move_min_to_top(b, target_pos_b); // Déplace la position dans B
	pb(a, b); // Pousse l'élément de A vers B
}

/* 5. Tri final et réinsertion dans STACK_A

Une fois que STACK_B est trié en ordre décroissant, nous devons réinsérer tous les éléments dans STACK_A.
 */


void sort_10(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		execute_optimal_move(a, b);

	sort_3(a); // Trie les trois éléments restants dans A

	while (b->size > 0)
		pa(a, b); // Réinsère les éléments de B à A
}

/* 6. Finalisation : mise en place du minimum au sommet

Cette fonction assure que le plus petit élément se trouve en haut de la pile STACK_A pour finaliser le tri. */


void finalize_sort(t_stack *a)
{
	int min_index;

	find_min(a, NULL, &min_index);
	move_min_to_top(a, min_index);
}

/* Mise en œuvre pour 10 */


void sort_10(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		execute_optimal_move(a, b);

	sort_3(a);

	while (b->size > 0)
		pa(a, b);

	finalize_sort(a);
}



1. Décomposer le problème en plusieurs parties

Avec 100 ou 500 éléments, essayer de trouver le coût pour chaque élément individuellement serait trop lent et inefficace. Une approche plus pragmatique consiste à diviser STACK_A en plusieurs segments ou "chunks" et de traiter chaque chunk séparément.
2. Diviser STACK_A en chunks

L'idée est de diviser STACK_A en segments ou "chunks" de taille fixe. On peut commencer par diviser en 5 ou 10 chunks, en fonction du nombre total d'éléments.

c

void chunk_sort(t_stack *a, t_stack *b, int chunk_size)
{
	int chunk_start;
	int chunk_end;

	chunk_start = 0;
	while (chunk_start < a->capacity)
	{
		chunk_end = chunk_start + chunk_size;
		if (chunk_end > a->capacity)
			chunk_end = a->capacity;

		push_chunk_to_b(a, b, chunk_start, chunk_end);
		chunk_start = chunk_end;
	}
	reinsert_sorted_b_to_a(a, b);
}

3. Pousser chaque chunk de STACK_A à STACK_B

Ensuite, pour chaque chunk, vous sélectionnez les éléments qui appartiennent à ce chunk et les poussez à STACK_B, en utilisant l'approche de coût minimale décrite précédemment.

c

void push_chunk_to_b(t_stack *a, t_stack *b, int chunk_start, int chunk_end)
{
	int i;

	while (chunk_size > 0)
	{
		i = 0;
		while (i < a->size)
		{
			if (a->data[i] >= chunk_start && a->data[i] < chunk_end)
			{
				execute_optimal_move(a, b, i); // Déplace l'élément à la meilleure position dans B
				chunk_size--;
			}
			i++;
		}
	}
}

4. Réinsertion des éléments de STACK_B à STACK_A

Une fois que tous les éléments sont triés dans STACK_B, vous les réinsérez dans STACK_A en utilisant une approche similaire, en vous assurant que chaque élément est placé à sa position correcte dans STACK_A.

c

void reinsert_sorted_b_to_a(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		move_max_to_top(b); // Assure que l'élément maximal est en haut de B
		pa(a, b); // Pousse l'élément de B à A
	}
}

5. Fonction principale pour le tri de 100 ou 500 éléments

Voici comment intégrer tout cela dans une fonction unique qui triera les éléments :

c

void sort_large_stack(t_stack *a, t_stack *b)
{
	int chunk_size;

	chunk_size = a->capacity / 10; // Diviser en 10 chunks (à ajuster selon les performances)
	if (chunk_size == 0)
		chunk_size = 1;
	chunk_sort(a, b, chunk_size);
	finalize_sort(a); // Mise en place du minimum en haut de la pile A
}

Détails supplémentaires

    move_max_to_top : Cette fonction déplace l'élément maximum de STACK_B au sommet avant de le pousser dans STACK_A.
    finalize_sort : Cette fonction vérifie que STACK_A est bien trié en s'assurant que le plus petit élément est en haut.

Conclusion

Cette méthode n'est pas aussi rapide qu'un algorithme comme Radix Sort, mais elle reste efficace pour trier 100 ou 500 éléments en utilisant des concepts simples. L'utilisation de chunks permet de gérer un grand nombre d'éléments en petits blocs, rendant l'algorithme plus maniable et performant sur des stacks plus importants.
