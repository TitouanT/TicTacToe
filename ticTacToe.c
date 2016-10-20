#include <stdio.h>
#include "constante_typePerso.h"
#include "verification.h"
#include "ticTacToe.h"

int main () {
  int etat = CONTINUER, ligne, colonne;
  t_pion grille[N][N], joueur = rond;

  char nomFichier[30];
  printf ("Dans quel fichier souhaité vous enregistrer la partie ? ");
  scanf ("%s", nomFichier);
  FILE * file = fopen (nomFichier, "a");
  fprintf (file, "Début de la partie:\n");
  fclose(file);

  initGrid (grille); // initialisation de la grile


  while (etat == CONTINUER) { // tant que personne ne gagne et qu'il n y a pas d'egalité
    afficherGrille(grille);

    // on inverse les joueur au debut de la boucle pour avoir le gagnant a la sortie.
    if (joueur == rond) joueur = croix;
    else joueur = rond;

    do {

      if (joueur == rond) printf ("c'est à O de jouer (ligne, colonne): ");
      else printf ("c'est à X de jouer (ligne, colonne): ");

      scanf ("%d%d", &ligne, &colonne);

    } while (verifCoup (grille, ligne, colonne) == 0);

    grille[ligne][colonne] = joueur; // on place le pion du joueur

    ecrireGrille (grille, nomFichier); // on enregistre l'etat de la grille

    etat = verifierFin (grille, ligne, colonne); // on test pour savoir si il faut sortir de la boucle
  }
  afficherGrille(grille);

  if (etat == WINNER) {
    printf ("Le gagnant est %c !!\n", (joueur == rond) ? 'O' : 'X');
  }
  else if (etat == FULL) {
    printf ("La grille est pleine, personne ne gagne !\n");
  }
  else printf ("Ce cas ne devrait jamais se produire ! \n");

  return 0;
}

void ecrireGrille (t_pion grille[][N], char *nomFichier) {
  FILE * file = fopen (nomFichier, "a");
  int i, j;
  for (i = 0; i < N; i++) {
    fprintf (file, "|");
    for (j = 0; j < N; j++) {
      switch (grille[i][j]) {
        case vide : fprintf(file, " |"); break;
        case croix: fprintf(file, "X|"); break;
        case rond : fprintf(file, "O|");
      }
    }
    fprintf (file, "\n");
  }
  fprintf (file, "\n\n");
  fclose(file);
}

void initGrid (t_pion grille[N][N]) {
  int i, j;
  for (i = 0; i < N; i++) for (j = 0; j < N; j++) {
    grille[i][j] = vide;
  }
}

void afficherGrille (t_pion grille[N][N]) {
  int i, j;
  clear();

  printf("  |");
  for (i = 0; i < N; i++) printf("%d|", i);
  printf ("\n");

  for (i = 0; i < N; i++) {
    printf ("%d |", i);
    for (j = 0; j < N; j++) {
      switch (grille[i][j]) {
        case vide : printf(" |"); break;
        case croix: printf("X|"); break;
        case rond : printf("O|");
      }
    }
    printf ("\n");
  }
}

void clear () {
  printf ("\e[1;1H\e[2J");
}
