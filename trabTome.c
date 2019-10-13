#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	double e, emax, erro, soma1, soma2, soma3;
	int i, j, itmax, k, k1; //k1 = k+1 pra nao confundir
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
	
	x = (double*)malloc(itmax+1*sizeof(double));		// fiz uma matriz pra por os resultados das iteracoes x^[k], onde k vai de 0 a itmax(k+1). ela tem n linhas e itmax colunas.
	for (i = 0; i < itmax+1 ; i++){
		x[i] = (double*)malloc(lin*sizeof(double));
	}

	for(i = 0; i < n; i++){		//atribuo valores pro x^(0)[k=0]
		x[0][i] = 0;
	}
	
	err = (double*)malloc(lin*sizeof(double));
	
	
	//calculo de cada iteraçao

	erro = 100;
	while(erro >= e){
		
		for (k1 = 1; k1 <= itmax + 1 ; k1++){
			//quebra  loop quando k+1>itmax
			if (k1 > itmax){
				printf("metodo diverge");
				break;
			}
			
			//calculo do X[k+1]
			// primeiro faço os somatorios
			
			for (i = 0 ; i < lin ; i++){
				soma1 = 0;
				soma2 = 0;
				//soma3 = 0;
				for (j = 0; j <= i - 1; j++){  			//matriz L
					soma1 += matrizA[i][j] * x[k1][j];  //tem alguma coisa estranha aqui, pq eh x[j] e nao x[i] ?
				}
				
				for (j = i+1; j < n; j++){				//matriz U
					soma2 += matrizA[i][j] * x[k1-1][j];
				}
				//atribuo o valor de x[k] pra cada linha
				soma3 = vetB[i] - soma1 - soma2;
				x[k1][i] = soma3 / matrizA[i][i];
			}
			
		
		
			//CALCULO DO MODULO DO ERRO.
			// max ||x[k][n] - x[k+1][n]||, n = 0,1,2...lin
			for (i = 0 ; i < lin; i++){
				err[i] = x[k1-1][i]-x[k1][i];
				
				if (err[i] < 0){
					err[i] *= -1;
				}
			}
			// norma infinita, já temos o vetor modulo, so peguei o maximo dele.
			emax = err[0];
			for (i = 1; i < n; i++){
				if (err[i] > err[i-1]){
					emax = err[i];
				}
			}
			erro = emax; 			// se o erro for menor ou igual a e, o loop do while acaba
			k = k1;
		}
	}	
	
	printf("acabou\n");
	for (i = 0 ; i < lin ; i++){
		printf("%1d\n",x[k][i]);
	}
	

 //nem sei
	//for(i =0;i<n;i++){}

	return 0;
}