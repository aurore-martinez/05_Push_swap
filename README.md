# 🚀 Push_swap

Bienvenue dans **Push_swap**, le défi ultime pour trier une pile en un minimum de coups ! 🎩✨
Si tu aimes les algos d'optimisation et les casse-têtes, ce projet est fait pour toi.

---

## 🎯 Objectif

L'objectif de **Push_swap** est simple (en apparence) :
Tu reçois une pile de nombres en désordre et tu dois la trier avec un ensemble limité d'opérations. 🃏🎭

Mais attention... **chaque mouvement compte** ! 🔥 Ton but est de **minimiser** le nombre d'opérations utilisées.

---

## 🛠️ Utilisation

1. **Compilation** ⚙️
   ```bash
   make
   ```
   Cela génère l'exécutable `push_swap`.

2. **Lancer le programme** 🎮
   ```bash
   ./push_swap 4 3 2 1
   ```
   Le programme affiche la liste des opérations nécessaires pour trier ces nombres.

3. **Vérification des résultats** ✅
   Pour voir si ton algo est bon, utilise le **checker_linux** :
   ```bash
   ./push_swap 4 3 2 1 | ./checker_linux 4 3 2 1
   ```
   Si tout est bon, il te dira `OK`, sinon `KO` ! 🚨

4. **Tester avec le script magique** 🧙‍♂️
   J'ai préparé un **script de tests** qui reprend toute la grille d'évaluation ! 🏆
   Il suffit de le lancer pour voir où tu te situes en termes de performances :
   ```bash
   ./tests.sh
   ```
   Résultats immédiats et sans effort ! 💡

---

## 📌 Exemples

🔹 **Cas simple**
```bash
./push_swap 3 2 1
```
📜 **Sortie attendue**
```
sa
rra
```
(Ça peut varier en fonction de ton algo)

🔹 **Vérification avec le checker**
```bash
./push_swap 3 2 1 | ./checker_linux 3 2 1
```
💡 **Sortie attendue**
```
OK
```

🔹 **Test automatique**
```bash
./tests.sh
```
📊 **Valgrind**
```bash
valgrind ./tests.sh
```

---

## 🎉 Amuse-toi bien !

Si tu arrives à faire mieux que l'évaluation minimale, tu es un **boss** 🔥 !
Et surtout... n’oublie pas que **moins d’opérations = plus de respect** 🏆

Happy sorting! 🚀
