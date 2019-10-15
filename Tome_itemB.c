#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {
	double e, auxiliar, emax = 1000;
	int i, j, itmax;
	int lin, col, k;
	int aux, n;
	int *vetB;
	int **matrizA;
	double *x, *xantes, *eit, *err;

  printf("Digite o tamanho da matriz pentadiagonal:  ");
  scanf("%d", &n);

  lin = n;
  col = n;

  matrizA = (int **)malloc(col*sizeof(int*));

  for(i = 0; i<col; i++){
    matrizA[i] = (int *)malloc(lin*sizeof(int));
  }

  for (i = 0; i < col; i++) {
    for (j = 0; j < lin; j++) {
      if(i == j){
        matrizA[i][j] = 5;
      }
      else if ( i == j+1 || i == j+3 || i+1 == j || i+3 == j) {
        matrizA[i][j] = -1;
      } else {
        matrizA[i][j] = 0;
      }
      printf("%3d", matrizA[i][j]);      
    }
    puts("");
  }

  //printf("Digite os valores do seu vetor B:  ");

  vetB = (int *)malloc(n *sizeof(int));
	
  vetB[0] = 3;
  vetB[n-1] = 3; 
  for (i = 1; i < n-1; i++) {
    //scanf("%d", &aux);
    vetB[i] = 2;
  }

 	x = (double*)malloc(n*sizeof(double));
	xantes = (double*)malloc(n*sizeof(double));
	
 	//printf("Digite os valores iniciais do seu vetor X:  ");

 	for(i = 0; i < n; i++){
		//scanf("%lf", &auxiliar);
		x[i] = 0;
		xantes[i] = 0;
	}

	printf("Digite o valor do erro:  ");
	scanf("%lf", &e);	

	printf("Digite a quantidade maxima de iteraçoes que o codigo pode ter:  ");
	scanf("%d",&itmax);
	
	double sum;
 	sum = 0.0;
	k = 0;
 	eit = (double*)malloc(n*sizeof(double));
	
	while (k < itmax){
  		for(i=0; i<n; i++){
  			for(j = 0; j < n; j++){
  				sum = sum + matrizA[i][j]*x[j];
 			}
   			x[i] = (vetB[i] - sum + matrizA[i][i]*x[i])/matrizA[i][i];
			eit[i] = fabs(x[i]-xantes[i]);
			printf("%lf \n", eit[i]);
			xantes[i] = x[i];
			sum = 0.0;
  		}
		emax = eit[0];
		for(i = 1; i < n; i++){
			if (eit[i] > eit[i-1]){
				emax = err[i];
			}
		}
		
		if (emax <= e){
			printf("\n O vetor x eh = \n");
			for (i = 0; i < n; i++){
				printf("%lf \n", x[i]);
			}
			return 0;
		}
  		k++;
 	}
 	printf("Metodo diverge");
  	return 0;
}


