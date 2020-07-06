#include "are_bi_par.h"

int main(){
// test
//    T_Inter inter1= {531,602};
//    T_Arbre ABR = creer_noeud (12,inter1);
//
//    T_Noeud noeud1 ={10,{714,715},NULL,NULL};
//    ajouter_noeud(&ABR, &noeud1);
//    T_Noeud noeud2 ={14,{320,322},NULL,NULL};
//    ajouter_noeud(&ABR, &noeud2);
//    T_Noeud noeud3 ={2,{819,821},NULL,NULL};
//    ajouter_noeud(&ABR, &noeud3);
//    T_Noeud noeud4 ={3,{650,670},NULL,NULL};
//    ajouter_noeud(&ABR, &noeud4);
//    T_Noeud noeud5 ={12,{214,220},NULL,NULL};
//    ajouter_noeud(&ABR, &noeud5);
//    T_Noeud noeud6 ={10,{412,415},NULL,NULL};
//    ajouter_noeud(&ABR, &noeud6);
//    T_Noeud noeud7 ={5,{725,730},NULL,NULL};
//    ajouter_noeud(&ABR, &noeud7);
//
//    printf("Afficher toutes les reservations \n");
//    affiche_abr(ABR);
//
//    T_Inter inter2 = noeud2.interval;
//    Supp_noeud(&ABR, inter1, 12);
//    printf("\napres la suppresssion ,Afficher toutes les reservations \n");
//    affiche_abr(ABR);
//    printf("\nAfficher toutes les reservations sur 10 \n");
//    affiche_entr(ABR,10);
//    printf("\nAfficher toutes les reservations sur 12\n");
//    affiche_entr(ABR,12);
//    detruire_arbre(&ABR);
//    printf("\n\nAfficher toutes les reservations apres detruire l'arbre!!\n");
//    affiche_abr(ABR);
//    return 0;

    T_Noeud * ABR=NULL;
    int opt=0;
    int opt1 ;
    int opt2 ;
    int opt3 ;
    int opt4 ;
    int opt5 ;
    while (opt!=8)
    {
        printf("-------------------------------------------------Menu-------------------------------------------------\n");
        printf("1)Creer un ABR\n");
        printf("2)Afficher tous les reservations\n");
        printf("3)Ajouter une reservation\n");
        printf("4)Modifier une reservation\n");
        printf("5)Supprimer une reservation\n");
        printf("6)Afficher les reservations d'une entreprise\n");
        printf("7)Supprimer l'arbre\n");
        printf("8)Quitter\n\n");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1 :    printf("*********************************Creer un ABR !*****************\n\n");
                    printf("Veuillez-vous entrer le id_entreprise!\n");
                    scanf("%d",&opt1);
                    printf("Veuillez-vous entrer le borne_gauche,borne_droite(Form: _,_ )!\n");
                    T_Inter interval;
                    scanf("%d,%d",&(interval.b_g),&(interval.b_d));
                    ABR = creer_noeud (opt1, interval);
                    break;
        case 2 :
                    printf("Afficher tous les reservations!\n");
                    affiche_abr(ABR);
                    break;
        case 3 :
                    printf("Ajouter une reservation!\n");
                    T_Noeud * noeud=malloc(sizeof(T_Noeud));//ÒÔºóÒ»¶šÒª×¢Òâ³õÊŒ»¯!!!
                    T_Inter interv ;
                    printf("Veuillez-vous entrer le id_entreprise que vous voulez consulter!\n");
                    scanf("%d",&opt2);
                    printf("Veuillez-vous entrer le borne_gauche,borne_droite(Form: _,_ )!\n");
                    scanf("%d,%d",&(interv.b_g),&(interv.b_d));
                    noeud->interval=interv;
                    noeud->ID_Entr = opt2;
                    noeud->filsG=NULL;
                    noeud->filsD=NULL;
                    ajouter_noeud(&ABR,noeud);
                    break;
        case 4 :
                    printf("Modifier une reservation!\n");
                    printf("Veuillez-vous entrer le id_entreprise que vous voulez modifier!\n");
                    scanf("%d",&opt3);
                    T_Inter interv1;
                    T_Inter interv2;
                    printf("Veuillez-vous entrer le borne_gauche,borne_droite(Form: _,_ )!\n");
                    scanf("%d,%d",&(interv1.b_g),&(interv1.b_d));
                    printf("Veuillez-vous entrer le borne_gauche,borne_droite(Form: _,_ )//Nouvelle_inter!\n");
                    scanf("%d,%d",&(interv2.b_g),&(interv2.b_d));
                    modif_noeud(&ABR,interv1, opt3, interv2);
                    break;
        case 5 :
                    printf("Supprimer une reservation!\n");
                    printf("Veuillez-vous entrer le id_entreprise que vous voulez modifier!\n");
                    scanf("%d",&opt4);
                    T_Inter interv3;
                    printf("Veuillez-vous entrer le borne_gauche,borne_droite(Form: _,_ )!\n");
                    scanf("%d,%d",&(interv3.b_g),&(interv3.b_d));
                    Supp_noeud(&ABR,interv3, opt4);
                    break;
        case 6 :
                    printf("Afficher les reservations d'une entreprise!\n");
                    printf("Veuillez-vous entrer le id_entreprise que vous voulez afficher!\n");
                    scanf("%d",&opt5);
                    affiche_entr(ABR,opt5);
                    break;
        case 7 :
                    printf("Supprimer l'arbre!\n");
                    detruire_arbre(&ABR);
                    break;
        case 8 :    printf("Bye-Bye!!!\n");
                    break;
        default :   printf("veuillez-vous entrer correctement!!!\n");
                    break;
            }
    }
    return 0;
}
