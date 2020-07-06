#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct inter {
    int b_g;
    int b_d;
} T_Inter;
typedef struct Noeud T_Noeud;
struct Noeud {
    int ID_Entr;
    T_Inter interval;
    T_Noeud * filsG;
    T_Noeud * filsD;
};
typedef T_Noeud * T_Arbre;





//Les fonctions supplšŠmentaires
extern T_Noeud * creer_noeud (int Id_entreprise, T_Inter intervalle);
extern int ajouter_noeud(T_Arbre * abr, T_Noeud * noeud);
extern T_Noeud * recherche (T_Arbre abr, T_Inter intervalle, int Id_entreprise);
extern void Supp_noeud(T_Arbre * abr, T_Inter intervalle, int Id_entreprise);
extern void modif_noeud(T_Arbre *abr, T_Inter intervalle, int Id_entreprise, T_Inter NouveIntervalle);
extern void   affiche_abr(T_Arbre abr );
extern void affiche_entr(T_Arbre abr,int Id_entreprise);
extern void detruire_arbre(T_Arbre *abr);
//Les fonctions supplšŠmentaires
extern T_Arbre pere(T_Arbre Ra_abr,T_Arbre noeu_re);
extern T_Arbre Minimum(T_Arbre abr);
extern T_Arbre Successeur(T_Arbre Ra_abr,T_Arbre x);
