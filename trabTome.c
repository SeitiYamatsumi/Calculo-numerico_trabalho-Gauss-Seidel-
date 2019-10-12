#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	double e, emax, erro;
	int i, j, itmax, k;
	int lin, col;
	int aux, n, nB;
	int *vetB;
	int **matrizA;
	double **x;
	double *err;

	printf("Digite o tamanho da matriz pentadiagonal:  ");
	scanf("%d", &n);

	lin = n;
	col = n;

	matrizA = (int *)malloc(col*sizeof(int));
	
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
		printf("%10d", matrizA[i][j]);      
		}
		puts("");
	}

	printf("Digite os valores do seu vetor B:  ");
	//scanf("%d", &nB);

	vetB = (int *)malloc(n *sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", &aux);
		vetB[i] = aux;
	}
	printf("Digite o valor de e:");
	scanf("%lf", &e);
	
	printf("Digite o valor de itmax:");
	scanf("%d",&itmax);
	
	x = (double*)malloc(itmax+1*sizeof(int));		// fiz uma matriz pra por os resultados das iteracoes x^[k], onde k vai de 0 a itmax(k+1). ela tem n linhas e itmax colunas.
	for (i = 0; i < itmax+1 ; i++){
		x[i] = (double*)malloc(lin*sizeof(int));
	}

	for(i = 0; i < n; i++){
		x[0][i] = 0;
	}
	
	err = (double*)malloc(lin*sizeof(int));
	
	//calculo de cada iteraçao
	
	for (k = 1; k <= itmax + 2 ; k++){
		while(erro >= e){
			if (k + 1 > itmax){
				printf("metodo diverge");
				break;
			}
			//calculo do X[k+1]
			
		
		
			//CALCULO DO MODULO DO ERRO.
			// max ||x[k][n] - x[k+1][n]||, n = 0,1,2...lin
			for (i = 0 ; i < lin; i++){
				err[i] = x[k][i]-x[k-1][i]; //nesse caso k+1 vira k e k vira k-1 ?
				
				if (err[i] < 0){
					err[i] *= -1;
				}
			}
			emax = err[0];
			for (i = 1; i < n; i++){
				if (err[i] > err[i-1]){
					emax = err[i];
				}
			}
			
			erro = emax; 		// se o erro for memor ou igual a e, o loop do while acaba.
			
		}
		printf("acabou");
			break;
	}	
	


	for(i =0;i<n;i++){
  
	}

	return 0;
}