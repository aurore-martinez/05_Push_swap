#!/bin/bash

# Nom du programme
PROGRAM="./push_swap"
CHECKER="./checker_linux"

# Fonction pour compter le nombre d'instructions
count_instructions() {
  local output=$1
  local count=$(echo "$output" | wc -l)
  echo "$count"
}

# Fonction pour tester les arguments et vérifier les instructions
test_args() {
  local args=$1
  local expected_max_instructions=$2
  echo "Testing with: $args"

  # Capture les instructions
  local instructions
  instructions=$(./push_swap $args)

  # Compte les instructions
  local count
  count=$(count_instructions "$instructions")

  # Vérifie que le nombre d'instructions est <= expected_max_instructions
  if [ "$count" -le "$expected_max_instructions" ]; then
    echo "Number of instructions: $count (OK)"
  else
    echo "Number of instructions: $count (FAIL)"
  fi

  # Exécute checker_linux
  echo "Exécute checker_linux" :
  echo "$instructions" | $CHECKER $args
}

# Fonction pour exécuter un test
run_test() {
    local cmd="$1"
    local expected="$2"

    echo "Running: $cmd"
    echo "Expected: $expected"

    # Exécution de la commande et capture du résultat
    result=$($cmd 2>&1)

    # Affichage du résultat
    echo "Result: $result"

    # Vérification du résultat attendu
    if [[ "$result" == "$expected" ]]; then
        echo "Test Passed"
    else
        echo "Test Failed"
    fi

    echo "---------------------------"
}

echo "Running error management tests..."

# Tests de gestion des erreurs
run_test "$PROGRAM one" "Error"
run_test "$PROGRAM one 1 3" "Error"
run_test "$PROGRAM \"one\"" "Error"
run_test "$PROGRAM \"one 1 3\"" "Error"
run_test "$PROGRAM \"1 1\"" "Error"
run_test "$PROGRAM 1 1" "Error"
run_test "$PROGRAM \"2147483648 2\"" "Error"
run_test "$PROGRAM 2147483648 2" "Error"
run_test "$PROGRAM -2147483649 3 6" "Error"
run_test "$PROGRAM \"-2147483649 3 6\"" "Error"
run_test "$PROGRAM" ""  # Aucun message attendu pour les arguments vides
run_test "$PROGRAM 42" ""  # Aucun message attendu pour un seul nombre

echo "Running sorted list tests..."

# Tests de tri (liste déjà triée)
run_test "$PROGRAM 42" ""  # Liste déjà triée, donc pas de sortie
run_test "$PROGRAM 2 3" ""  # Liste déjà triée, donc pas de sortie
run_test "$PROGRAM 0 1 2 3" ""  # Liste déjà triée, donc pas de sortie
run_test "$PROGRAM 0 1 2 3 4 5 6 7 8 9" ""  # Liste déjà triée, donc pas de sortie

echo "Running tests with random values..."

# Test avec 5 valeurs aléatoires entre 0 et 99
echo "Test avec 5 valeurs aléatoires entre 0 et 99"
ARG=$(shuf -i 0-99 -n 5 | tr '\n' ' ')
test_args "$ARG" 12

# Test avec 100 valeurs aléatoires entre 0 et 999
echo "Test avec 100 valeurs aléatoires entre 0 et 999"
ARG=$(shuf -i 0-99 -n 100 | tr '\n' ' ')
test_args "$ARG" 1500  # Ajuster en fonction des critères de taille d'instructions pour 100 valeurs

# Test avec 500 valeurs aléatoires entre 0 et 999
echo "Test avec 500 valeurs aléatoires entre 0 et 999"
ARG=$(shuf -i 0-500 -n 500 | tr '\n' ' ')
test_args "$ARG" 11500  # Ajuster en fonction des critères de taille d'instructions pour 500 valeurs


# Test avec des valeurs spécifiques
echo "Testing specific values..."

# Exemple spécifique pour vérifier le comportement
SPECIFIC_ARGS="1 9 6 2 3"
test_args "$SPECIFIC_ARGS" 12

echo "Tests completed."
