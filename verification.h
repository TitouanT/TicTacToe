#ifndef VERIFICATION_H
#define VERIFICATION_H

#include "constante_typePerso.h"

/// cette fonction renvoi WINNER si un joueur a gagné, FULL si la grille est pleine et CONTINUE sinon.
int verifierFin (t_pion grille[][N], int ligne, int colonne);

/// vérifie si le pion ajouté est dans un alignement de trois Horizontal, renvoi 1 si oui, 0 sinon.
int verifH (t_pion grille[][N], int ligne, int colonne);

/// vérifie si le pion ajouté est dans un alignement de trois Vertical, renvoi 1 si oui, 0 sinon.
int verifV (t_pion grille[][N], int ligne, int colonne);

/// vérifie si le pion ajouté est dans un alignement de trois dans la premiere diagonale, renvoi 1 si oui, 0 sinon.
int verifD1 (t_pion grille[][N], int ligne, int colonne);

/// vérifie si le pion ajouté est dans un alignement de trois dans la seconde diagonale, renvoi 1 si oui, 0 sinon.
int verifD2 (t_pion grille[][N], int ligne, int colonne);

/// vérifie si le coup que veut jouer le joueur est autorisé
int verifCoup (t_pion grille[N][N], int ligne, int colonne);

#endif
