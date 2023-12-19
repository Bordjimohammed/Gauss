#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,k,ligne,n;
    float A[20][20],m,b[10],x[10],ref, temp, s=0;
    printf("\n Saisir l'ordre du systeme lineaire a resoudre n= ");
    scanf("%d",&n);
    printf("\n Saisir les elements de la matrice augnentee : \n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("A[%d][%d] : ", i,j);
            scanf("%f",&A[i][j]);
        }
    }
    printf("\n * Le vecteur b:\n\n");
    for(i=1;i<=n;i++){
//printf(" | ");
        printf("b[%d]= ", i);
        scanf("%f",&b[i]);
    }
    printf("\n Votre matrice augmentée est comme suit : \n");
    printf("\n\n");
    for (i=1; i<=n; i++)
    {
        printf(" [");
        for (j=1; j<=n; j++)
        {
            printf(" %f", A[i][j]);
        }
        printf("] [ %.f ]",b[i]);
        printf("\n");
    }
    for(k=1;k<=(n-1);k++){
// max pour le pivot partiel
        ref=0;
        for(i=k;i<=n;i++)
            if(fabs(A[i][k])>ref){
                ref=fabs(A[i][k]);ligne=i;
            }



// pivotations
        for(j=k;j<=n;j++){
            temp=A[k][j]; A[k][j]=A[ligne][j];A[ligne][j]=temp;
        }
        temp=b[k]; b[k]=b[ligne]; b[ligne]=temp;
        if (A[k][k]==0)
            printf("\n* Un pivot nul ! => Méthode de Gauss pivot partiel non applicable");
        for(i=k+1;i<=n;i++){
            m=A[i][k]/A[k][k];
            for (j=k;j<=n;j++) A[i][j]=A[i][j]-m*A[k][j];
            b[i]=b[i]-m*b[k];
        }
    }
    printf(" \n Votre systeme triangulaire superieur est comme suit : \n\n ");
    printf("\n\n");
    for (i=1; i<=n; i++)
    {
        printf(" [");
        for (j=1; j<=n; j++)
        {
            printf(" %f", A[i][j]);
        }
        printf("] [ %.f ]",b[i]);
        printf("\n");
    }
// Résolution
    x[n]=b[n]/A[n][n];
/* this loop is for backward substitution*/
    for(i=n-1; i>=1; i--)
    {
        s=0;
        for(j=i+1; j<=n; j++)
        {
            s=s+A[i][j]*x[j];
        }
        x[i]=(b[i]-s)/A[i][i];
    }
    printf("\n\nLe vecteur solution de votre système linéaire est x= : \n");
    for(i=1; i<=n; i++)
    {
        printf("\n x(%d)=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
    }
}
