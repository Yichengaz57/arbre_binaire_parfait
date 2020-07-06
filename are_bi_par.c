#include "are_bi_par.h"


//Fonctions requises
T_Noeud * creer_noeud (int Id_entreprise, T_Inter intervalle)
{
    T_Arbre newnoeud = (T_Arbre)malloc(sizeof(T_Noeud));
    newnoeud->ID_Entr = Id_entreprise;
    newnoeud->interval = intervalle;
    newnoeud->filsG = NULL;
    newnoeud->filsD = NULL;
    return newnoeud;
}

int ajouter_noeud(T_Arbre * abr, T_Noeud * noeud)
{
    T_Arbre A = * abr;
    if (A == NULL)
    {
        printf("Il faut d'abord creer l'ABR!!\n\n");
        return 0;
    }

    else if((A->interval).b_g > (noeud->interval).b_d)
        {
            if(A->filsG == NULL)
                A->filsG = noeud;
            else ajouter_noeud(&(A->filsG),noeud);
        }
    else if((A->interval).b_d < (noeud->interval).b_g)
        {
            if(A->filsD == NULL)
                A->filsD = noeud;
            else ajouter_noeud(&(A->filsD),noeud);
        }
    else {
            printf("---erreur---!!!--I et I' se chevauchent\n");
            return 0;
        }
    return 1;
}

T_Noeud * recherche (T_Arbre abr, T_Inter intervalle, int Id_entreprise)
{
    if (abr == NULL)
        return NULL;
    else if (((abr->interval).b_g == intervalle.b_g)&&(abr->ID_Entr == Id_entreprise))//ne peut pas mettre == entre deux structure
        return abr;
    else if ((abr->interval).b_g > intervalle.b_d)
        return recherche(abr->filsG,intervalle,Id_entreprise);
    else if ((abr->interval).b_d < intervalle.b_g)
        return recherche(abr->filsD,intervalle,Id_entreprise);
    else
    {
        printf("trouve pas!!\n");
        return NULL;
    }

}

void Supp_noeud(T_Arbre * abr, T_Inter intervalle, int Id_entreprise) // mettre double pointeur pour modifier la valeur
{
    T_Arbre A=*abr;  //A copier *abr mais ne peut pas modifer *abr !!!                                                                 //tete et milieu --discussion
    T_Noeud * noeu_re = recherche(A,intervalle,Id_entreprise);
    if (noeu_re == NULL)return;  // verifier si on trouve pas ,on sort !!
    else
    {

        T_Arbre pr = pere(A,noeu_re);
        char c='w';
        if(pr!=NULL)           //dicussion si pere est null--c'est a dire noeu_re est tete
            {
            if(pr->filsD == noeu_re) // si pr est NULL non structure marche pas
            c = 'D';
            else c = 'G';
            }
     if((noeu_re ->filsD == NULL)&&(noeu_re ->filsG == NULL))//noeu_re est au milleu
        {
            if (pr==NULL)
                A=NULL; // ABR n'est pas modifie
            else
            {
                if(c == 'D')
                    pr->filsD = NULL;
                else pr->filsG = NULL;
            }
            free(noeu_re);
            *abr =A;//  modifier ABR
        }
     else if(noeu_re ->filsD == NULL)
        {
            if (pr==NULL)
                A=noeu_re->filsG; // ABR n'est pas modifie
            else
            {
            if(c == 'D')
                pr->filsD = noeu_re->filsG;
            else pr->filsG = noeu_re->filsG;
            }
            free(noeu_re);
            *abr =A; //  modifier ABR
        }
     else if(noeu_re ->filsG == NULL)
        {
            if (pr==NULL)
                A=noeu_re->filsD; // ABR n'est pas modifie
            else
            {
            if(c == 'D')
                pr->filsD = noeu_re->filsD;
            else pr->filsG = noeu_re->filsD;
            }
            free(noeu_re);
            *abr =A; //  modifier ABR
        }
    else
        {
            T_Arbre noeu_suc =Successeur(A,noeu_re);
            T_Arbre pr2 = pere(A,noeu_suc);// prioritaire,car ensuite,on chaner la valeur de noeud, pere est null;
            (noeu_re)->ID_Entr=noeu_suc->ID_Entr; // ABR n'est pas modifie
            (noeu_re)->interval=noeu_suc->interval; // ABR n'est pas modifie
                if (pr2==noeu_re)
                {
                 (noeu_re)->filsD=noeu_suc->filsD;
                 free(noeu_suc);
                }
                else
                {
                 pr2->filsG=NULL;
                 free(noeu_suc);
                }
            if (pr==NULL)
                *abr =noeu_re; // ABR n'est pas modifie
        }
    }
}

void modif_noeud(T_Arbre *abr, T_Inter intervalle, int Id_entreprise, T_Inter NouveIntervalle)
{
    T_Arbre A = * abr;
    T_Arbre noeu_re = recherche (A,intervalle,Id_entreprise);
//    T_Inter tmpint=noeu_re->interval;
//    int tmpid = noeu_re->ID_Entr;
//    T_Noeud* tmpg= noeu_re->filsG;
//    T_Noeud* tmpd= noeu_re->filsD;
    if (noeu_re==NULL)
    {
        printf("trouve  pas !\n!");
        return;   // peux retourner
    }
    else
    {
        T_Noeud* new_tar=(T_Noeud*)malloc(sizeof(T_Noeud));


//            if(((noeu_re->interval).b_d>intervalle.b_g)||((intervalle.b_d)>(noeu_re->interval).b_g))
//            {
//                 printf("---erreur---!!!--I et I' se chevauchent\n");
//            return;
//            }
//        else{
            Supp_noeud(abr,intervalle,Id_entreprise);
            new_tar->interval=NouveIntervalle;
            new_tar->ID_Entr=Id_entreprise;
            new_tar->filsD=NULL;
            new_tar->filsG=NULL;
            if(ajouter_noeud(abr,new_tar)!=1)
            {
                new_tar->interval=intervalle;
                new_tar->ID_Entr=Id_entreprise;
                ajouter_noeud(abr,new_tar);
            }

//            }

    }
}

 void   affiche_abr(T_Arbre abr )
 {
     if(abr!=NULL)
     {
        affiche_abr(abr->filsG);
        printf("  -->   ID_Entr:%d   --   [%d,%d]\n",abr->ID_Entr,(abr->interval).b_g,(abr->interval).b_d);
        affiche_abr(abr->filsD);
     }

 }

void affiche_entr(T_Arbre abr,int Id_entreprise)
{
    if(abr!=NULL)
     {
         affiche_entr(abr->filsG,Id_entreprise);
         if(abr->ID_Entr == Id_entreprise)
         {
            printf("  -->   ID_Entr:%d   --   [%d,%d]\n",abr->ID_Entr,(abr->interval).b_g,(abr->interval).b_d);
         }
        affiche_entr(abr->filsD,Id_entreprise);
     }
}

void detruire_arbre(T_Arbre *abr)
{
//    T_Arbre noeud=*abr;
    if(*abr!=NULL)
     {
        detruire_arbre(&((*abr)->filsG));
        detruire_arbre(&((*abr)->filsD));
        free(*abr);// modifier ABR
        *abr =NULL; // !!
     }
}
//Les fonctions supplšŠmentaires
T_Arbre pere(T_Arbre Ra_abr,T_Arbre noeu_re)
{
    T_Arbre pr = Ra_abr;
    if (pr==noeu_re)
    {
        return NULL; //verifier si pere est null c'est a dire noeu_re est tete
    }
    while((pr->filsD != noeu_re)&&(pr->filsG != noeu_re))
        {
        if ((pr->interval).b_g < (noeu_re->interval).b_g)
            pr = pr->filsD;
        else if ((pr->interval).b_g > (noeu_re->interval).b_g)
            pr = pr->filsG;
        }
    return pr;
}
T_Arbre Minimum(T_Arbre abr)
{
    while(abr->filsG!=NULL)
        abr = abr->filsG;
    return abr;
}
T_Arbre Successeur(T_Arbre Ra_abr,T_Arbre x)
{
    if (x->filsD != NULL)
        return Minimum(x->filsD);
    T_Arbre y = pere(Ra_abr,x);
    while((y!=NULL)&&(x==y->filsD))
        {
        x = y;
        y = pere(Ra_abr,y);
        }
    return y;
}

