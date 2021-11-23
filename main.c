#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    AffichageMenu(){
        printf("\n");
        printf(" ***************| Menu Principal |****************\n");
        printf(" *    1 : creer un compte bancaire               *\n");
        printf(" *    2 : creer plusieurs comptes bancaires      *\n");
        printf(" *    3 : retrait ou depot                       *\n");
        printf(" *    4 : affichage                              *\n");
        printf(" *    5 : Fidelisation                           *\n");
        printf(" *    6 : quitte l application                   *\n");
        printf(" *************************************************\n");
        printf("\noption : ");

}

void    SousMenuAffichage(){
        printf("\n");
        printf(" **************************************| Menu D'affichage |******************************************\n");
        printf(" *  1 : Par Ordre Ascendant                                                                         *\n");
        printf(" *  2 : Par Ordre Descendant                                                                        *\n");
        printf(" *  3 : Par Ordre Ascendant(les comptes bancaire ayant un montant superieur a un chiffre introduit) *\n");
        printf(" *  4 : Par Ordre Descendant(les comptes bancaire ayant un montant superieur a un chiffre introduit)*\n");
        printf(" *  5 : Recherche par CIN                                                                           *\n");
        printf(" *  6 : Retour au menu principal                                                                    *\n");
        printf(" *  7 : quitte l application                                                                        *\n");
        printf(" ****************************************************************************************************\n");

}




int main()
{
// DECLARATION DES VARIABLE

    char CIN[100][10];
    char CinSearch[1][100];
    int account_number[2];
    char account_name[100][30];
    char fid_name[100][30];
    double montant[100];
    double NMontant[100];
    double mRetrait,mDepot,R,MUser;
    double RMontant[100],AscendantDescendantName[100];
    double debut,fin;
    int C,AffichageChoix,j,i,choice1,choice2,CompteSelect;
    int NouveauOperation,CF;
    C=0;
    account_number[0]=0;

// AFFICHAGE DE MENU

debut:

        AffichageMenu();
        scanf("%d",&choice1);

        if (choice1>6 || choice1<1){
            printf("Erreur ! : Cette option n'existe pas \n");
                goto debut;

        }
//GOTO RETRAIT ET DEPOT

        while(choice1==3 || choice1==4){

            if (account_number[0]==0){

                    printf("Attention !!! : Il n y a pas de compte, veuillez en creer un nouveau \n");

                    goto debut;
            }

            if(choice1==3){
                goto operation;

            }

            if (choice1==4){
                goto affichage;
            }
        }


//Introduire un compte bancaire

      while (choice1==1){

            printf("nom : ");
            scanf("%s",&account_name[C]);

            printf("cin : ");
            scanf("%s",&CIN[C]);

            printf("montant : ");
            scanf("%lf",&montant[C]);

            account_number[C]=1;
                       C++;
                      choice1-=1;    //pour sortir

            goto debut;

        }



//Introduire plusieurs comptes bancaires

         while(choice1==2){

            printf("\nCombien de comptes : ");
            scanf("%d",&choice2);

                for(i=C ; i<C+choice2 ;i++){
                    printf("nom :");
                    scanf("%s",&account_name[i]);

                    printf("cin :");
                    scanf("%s",&CIN[i]);

                    printf("montant :");
                    scanf("%lf",&montant[i]);
                    printf("\n");

                    account_number[i]=1;

                }

                                C=C+choice2;            //compteur
                                choice1-=2;             //pour sortir
                                goto debut;            // retour au menu principal

                }
//GOTO FIDELISATION

                    if(choice1==5){

                        goto Fidelisation;
                    }


//quitte l'application


                if (choice1==6){
                    goto exit;

                }

//Affichage le tableau des noms
operation:
system("cls");
        printf("choiser le numero de votre compte :\n");
        printf("----------------------\n\n");
        for( i=0 ; i<C ; i++){
            printf(" %d : %s \n\n",i+1,account_name[i]);
        }
        ope:
        printf("option : ");
        scanf("%d",&CompteSelect);

        if(CompteSelect>C){

            printf("Erreur ! : Cette option n'existe pas !!! \n\nNouveau ");
            goto ope;
        }

//RETRAIT ET DEPOT


        printf("\nChoisissez l operation que vous voulez :\n");
        printf("----------------------------------------\n");
        printf(" 1 : retrait\n");
        printf(" 2 : depot\n\n");
        oper:
        printf("option : ");
        scanf("%d",&choice1);

         if(choice1>2 || choice1<1){

            printf("Erreur ! : Cette option n'existe pas !!! \n\nNouveau ");
            goto oper;
        }






       while (choice1==1){
            montantRetrait:
                printf("montant retrait :");
                    scanf("%lf",&mRetrait);
                    if (mRetrait <= montant[CompteSelect-1]){
                        montant[CompteSelect-1] -= mRetrait;

                                choice1-=1;
                    }else{
                       printf("ce montant est tres grand !!!!\n\n");
                       goto montantRetrait;
                    }
        }

        while (choice1==2){
            printf("montant depot :");
                    scanf("%lf",&mDepot);
                  montant[CompteSelect-1] += mDepot;

                                choice1-=2;
        }


system("cls");
                    printf("\n*******************************\n");
                    printf("*     L operation a reussi    *\n");
                    printf("*******************************\n\n");
                    printf("Details\n");
                    printf("--------\n\n");
                    printf("Nom             : %s\n",account_name[CompteSelect-1]);


                    printf("Cin             : %s\n",CIN[CompteSelect-1]);


                    printf("Nouveau Montant :%.2lf DH\n",montant[CompteSelect-1]);


                    goto debut;



affichage:

            SousMenuAffichage();
            printf("\noption : ");
            scanf("%d",&AffichageChoix);
            printf("\n ");

            for(i=0 ; i<C ;i++){
                RMontant[i] = montant[i];
            }


            if(AffichageChoix==1){

                goto Ascendant;
            }

            if(AffichageChoix==2){

                goto Descendant;
            }

            if(AffichageChoix==3){

                goto AscendantM;
            }

            if(AffichageChoix==4){

                goto DescendantM;
            }

            if(AffichageChoix==5){

                goto RechercheCIN;
            }


            if(AffichageChoix==6){

                goto debut;
            }
//quitte l'application


            if (AffichageChoix==7){
                    goto exit;
            }
             if (AffichageChoix>7 || AffichageChoix<1){
            printf("Erreur ! : Cette option n'existe pas \n");
                goto affichage;

        }


Ascendant:


             for(i=0 ; i<C ;i++){

                   for(j=0; j<C-1 ; j++){

                        if (RMontant[j]>RMontant[j+1]){
                            R=RMontant[j+1];
                            RMontant[j+1]=RMontant[j];
                            RMontant[j]=R;
                        }
                    }
             }

system("cls");
            printf("\n");
            for(i=0 ; i<C ;i++){
                printf("\t%.2lf",RMontant[i]);
            }
             printf("\n\n\n");



            goto affichage;

Descendant:


             for(i=0 ; i<C ;i++){

                   for(j=0; j<C-1 ; j++){

                        if (RMontant[j]<RMontant[j+1]){
                            R=RMontant[j+1];
                            RMontant[j+1]=RMontant[j];
                            RMontant[j]=R;
                    }
               }
            }

system("cls");
            printf("\n");
            for(i=0 ; i<C ;i++){
                printf("\t%.2lf",RMontant[i]);
            }
            printf("\n\n\n");

            goto affichage;

AscendantM:

    system("cls");

            printf("entrer un montant :");
            scanf("%lf",&MUser);



            for(i=0 ; i<C ;i++){

                   for(j=0; j<C-1 ; j++){

                        if (RMontant[j]>RMontant[j+1]){
                            R=RMontant[j+1];
                            RMontant[j+1]=RMontant[j];
                            RMontant[j]=R;
                        }
                    }
             }

            printf("\n");
             for(i=0 ; i<C ;i++){
                if (MUser<RMontant[i]){
                    printf("\t%.2lf",RMontant[i]);
                }
             }

             goto affichage;




DescendantM:

    system("cls");

                    printf("entrer un montant :");
            scanf("%lf",&MUser);



            for(i=0 ; i<C ;i++){

                   for(j=0; j<C-1 ; j++){

                        if (RMontant[j]>RMontant[j+1]){
                            R=RMontant[j+1];
                            RMontant[j+1]=RMontant[j];
                            RMontant[j]=R;
                        }
                    }
             }


             for(i=C-1 ; i>=0 ;i--){
                if (MUser<RMontant[i]){
                    printf("\t%.2lf",RMontant[i]);
                }
             }

             goto affichage;





RechercheCIN:
    system("cls");

            printf("entrer CIN :");
            scanf("%s",&CinSearch[0]);
            printf("-----------------------\n\n");


            for ( i=0 ; i<C ; i++){

                if (strcmp(CinSearch[0],CIN[i])==0){

                    printf("Nom             : %s\n",account_name[i]);


                    printf("Cin             : %s\n",CIN[i]);


                    printf("Montant         :%.2lf DH\n",montant[i]);


                }
            }

                    goto affichage;

Fidelisation:

                 for(i=0 ; i<C ;i++){
                    RMontant[i] = montant[i];
                }


                for(i=0 ; i<C ;i++){

                   for(j=0; j<C-1 ; j++){

                        if (RMontant[j]<RMontant[j+1]){
                            R=RMontant[j+1];
                            RMontant[j+1]=RMontant[j];
                            RMontant[j]=R;
                        }
                    }
                }
system("cls");

//CF NOMBRE DES BOUCLES
                            if( C<3 ){
                                CF=C;
                            }else{
                                CF=3;
                            }
//AFFICHAGE LES MONTANTS DE FIVELISATION

                                printf("----------------------------------------------------------------\n");
                for(i=0 ;i<CF ;i++){
                    NMontant[i]=RMontant[i]+((RMontant[i]*1.3)/100);
                        for (j=0 ; j<C ; j++){
                            if (RMontant[i]==montant[j]){

                                printf("name : %s   -   CIN : %s  -   Nouveau Montant : %.2lf DH\n",account_name[j],CIN[j],NMontant[i]);
                                printf("----------------------------------------------------------------\n");
                                printf("\n");

                            }
                        }
                }


//POUR REMPLACER LANCIEN MONTANT PAR MONTANT DE FIDELISATION

                for (i=0 ; i<3 ;i++){
                    for(j=0 ; j<C ;j++){
                        if (RMontant[i] == montant[j]){
                            montant[j] = NMontant[i];
                        }
                    }
                }





                    goto affichage;


exit:


    return 0;
}