//As partes da letra A estão comentadas e escritas (letra A).
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {

	double e, auxiliar, sum, emax = 1000;
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
	// Declaro a matriz A
	matrizA = (int **)malloc(col*sizeof(int*));
	for(i = 0; i<col; i++){
	  matrizA[i] = (int *)malloc(lin*sizeof(int));
	}

	// Insiro os valores propostos no enunciado na matriz A
	for (i = 0; i < col; i++) {
  	for (j = 0; j < lin; j++) {
    	if(i == j){
				matrizA[i][j] = 5;
    	}
    	else if ( i == j+1 || i == j+3 || i+1 == j || i+3 == j) {
      	matrizA[i][j] = -1;
    	}	else {
      	matrizA[i][j] = 0;
    	}
    	printf("%3d", matrizA[i][j]);
  	}
  	puts("");
	}

	//peço ao usuário digitar os valores do vetor B e atribuo os valores digitados em cada célula do vetor

	vetB = (int *)malloc(n *sizeof(int));
  vetB[0] = 3;
  vetB[n-1] = 3;
  for (i = 1; i < n-1; i++) {
    //scanf("%d", &aux);
    vetB[i] = 2;
  }
	//printf("Digite os valores do seu vetor B:  ");		(Letra A)
	/*for (i = 0; i < n; i++) {
	  scanf("%d", &aux);
	  vetB[i] = aux;
	}*/

	// Declaro o vetor x e o vetor xantes
	x = (double*)malloc(n*sizeof(double));
	xantes = (double*)malloc(n*sizeof(double));

	// Atribuo os valores para x[k=0] de acordo com o enunciado
	//printf("Digite os valores iniciais do seu vetor X:  ");   (letra A)
	for(i = 0; i < n; i++){
		//scanf("%lf", &auxiliar);																(letra A)
		x[i] = 0; 				//ou x[i] = auxiliar										(letra A)
		xantes[i] = 10;																						// 10 é só para ele não por lixo.
	}

// Atribuo os valores para o erro (e) e digo a quantidade de iterações maxima.
	printf("Digite o valor do erro(e):  ");
	scanf("%lf", &e);

	printf("Digite a quantidade maxima de iteracoes que o codigo pode ter:  ");
	scanf("%d",&itmax);

	// Defino o vetor que vai auxiliar no calculo do erro.
	eit = (double*)malloc(n*sizeof(double));

	// Começo as iterações.
	// Quando k = itmax, o for acaba e printa 'o metodo diverge'.
	k = 0;
	for (k = 0; k<itmax; ++k){

		// Cálculo das iterações: calculo a somatoria em cada linha e depois calculo x da linha correspondente.
		for(i=0; i<n; i++){
			
			sum = 0.0;													// Reseto o soma a cada linha
			
			for(j = 0; j < n; j++){
				if(i!=j){												// Não devemos pegar a diagonal pincipal da matriz A.
					
					sum = sum + matrizA[i][j]*x[j];   					// Cálculo do primeiro somatório
				}
			}
			x[i] = (vetB[i] - sum)/matrizA[i][i];	// Calculo o valor x(i) da iteração k.
		}

    // Cálculo do módulo do erro.
			// Neste for calculo o módulo do erro de cada linha e armazeno no vetor eit[] .
		for (i = 0; i<n;i++){
			
			eit[i] = fabs(x[i]-xantes[i]);
	      
			xantes[i] = x[i];
		}

			// Agora classifico o maior valor do vetor erro(módulo infinito) e armazeno o maior valor na variável emax
		emax = eit[0];
		for(i = 1; i < n; i++){
			if (eit[i] > eit[i-1]){
				emax = eit[i];
			}
		}
				// Quando emax fica menor que o erro digitado pelo usuário.
				// O programa printa o vetor x com os resultados convergidos e também o útimo vetor erro, que tende ao vetor nulo.
		if (emax <= e){
			printf("\n O vetor x eh = \n");
			for (i = 0; i < n; i++){
				printf("%lf \n", x[i]);
			}
			printf("\n O vetor erro eh = \n");
			for (i = 0; i < n; i++){
				printf("%lf \n", eit[i]);
			}

			return 0;
				// Se entrar nesse if, o programa acaba após printar os valores de x e erro, se não o for acaba e o programa printa que o método diverge.
		}
	}

	printf("Metodo GAUSS-SEIDEL divergiu");

	return 0;
}
