/* contient les header des fonctions ecrites dans ticTacToe.c */

#ifndef TICTACTOE_H
#define TICTACTOE_H

/// initialise la grille avec des case vides
void initGrid (t_pion grille[N][N]);

/// affiche la grille avec un guide de ligne et de colonne
void afficherGrille (t_pion grille[N][N]);

/// efface l'écran
void clear (void);

/// ecrit l'état de la grille dans le fichier dont le nom est passé en parametre.
/// le fichier est ouvert en mode ajout.
void ecrireGrille (t_pion grille[][N], char *nomFichier);

#endif
