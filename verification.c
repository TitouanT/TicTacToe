/// ce fichier contient les définition des fonction de vérification de coup et d'alignement.
#include "verification.h"

int verifH (t_pion grille[][N], int ligne, int colonne) {
  int j, nbAlign = 1;
  // on verifie dans un sens,
  j = colonne - 1;
  while (j >= 0 && grille[ligne][j] == grille[ligne][colonne]) {
    j--;
    nbAlign++;
  }

  // puis dans l'autre
  j = colonne + 1;
  while (j < N  && grille[ligne][j] == grille[ligne][colonne]) {
    j++;
    nbAlign++;
  }

  if (nbAlign == N) return 1;
  else return 0;
}

int verifV (t_pion grille[][N], int ligne, int colonne) {
  int i, nbAlign = 1;

  // on verifie dans un sens,
  i = ligne - 1;
  while (i >= 0 && grille[i][colonne] == grille[ligne][colonne]) {
    i--;
    nbAlign++;
  }

  // puis dans l'autre
  i = ligne + 1;
  while (i < N  && grille[i][colonne] == grille[ligne][colonne]) {
    i++;
    nbAlign++;
  }

  if (nbAlign == N) return 1;
  else return 0;
}

int verifD2 (t_pion grille[][N], int ligne, int colonne) {
  int i, j, nbAlign = 1;

  // on verifie dans un sens,
  i = ligne - 1;
  j = colonne + 1;
  while (i >= 0 && j < N && grille[i][j] == grille[ligne][colonne]) {
    i--;
    j++;
    nbAlign++;
  }

  // puis dans l'autre
  i = ligne + 1;
  j = colonne - 1;
  while (i < N && j >= 0 && grille[i][j] == grille[ligne][colonne]) {
    i++;
    j--;
    nbAlign++;
  }

  if (nbAlign == N) return 1;
  else return 0;
}

int verifD1 (t_pion grille[][N], int ligne, int colonne) {
  int i, j, nbAlign = 1;

  // on verifie dans un sens,
  i = ligne - 1;
  j = colonne - 1;
  while (i >= 0 && j >= 0 && grille[i][j] == grille[ligne][colonne]) {
    i--;
    j--;
    nbAlign++;
  }

  // puis dans l'autre.
  i = ligne + 1;
  j = colonne + 1;
  while (i < N && j < N && grille[i][j] == grille[ligne][colonne]) {
    i++;
    j++;
    nbAlign++;
  }

  if (nbAlign == N) return 1;
  else return 0;
}

int verifierFin (t_pion grille[][N], int ligne, int colonne) {
  int full = 1, i, j, alignement = 0;

  // il suffit d'une case vide pour que la grille ne soit pas pleine.
  for (i = 0; i < N; i++) for (j = 0; j < N; j++) {
    if (grille[i][j] == vide) full = 0;
  }

  if (verifD1(grille, ligne, colonne) || verifD2(grille, ligne, colonne) || verifH(grille, ligne, colonne) || verifV(grille, ligne, colonne)) alignement = 1;

  if (alignement == 1) return WINNER;
  else if (full == 1) return FULL;
  else return CONTINUER;
}

int verifCoup (t_pion grille[N][N], int ligne, int colonne) {
  // on regarde si ligne et colonne sont dans les bornes puis on verifie que que l'emplacement est vide.
  if (ligne < 0 || ligne >= N || colonne < 0 || colonne >= N || grille[ligne][colonne] != vide) return 0;
  else return 1;
}
