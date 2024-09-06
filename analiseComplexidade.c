#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Método não eficiente, lento, estudado para desenvolvimento de raciocínio
void bubbleSort(int *vetor, size_t tamanhoVetor) {
    int aux, j, temp;

    aux = tamanhoVetor - 1;

    do{
        j = 0;
        for(int i = 0; i < aux; i++){
            if(vetor[i] > vetor[i + 1]) {
                temp = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = temp;
                j = i;
            }
        }
        aux = j;
    } while(aux >= 1);
}

void quickSort(int *vetor, int esq, int dir) {
	int pivo, i = esq, j = dir, temp;
	pivo = vetor[(i+j)/2];
	
	do{
		while(vetor[i] < pivo){
			i++;
		}
		while(vetor[j] > pivo){
			j--;
		}
		if(i <= j){
			temp = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = temp;
			i++;
			j--;
		}
	}while(i <= j);
	if(esq < j){
		quickSort(vetor, esq, j);
	}
	if(dir >i){
		quickSort(vetor, i, dir);
	}
}

void printarVetor(int *vetor, size_t tamanhoVetor){
    for(int i = 0; i < tamanhoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");   
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int vetor1[10];
    int vetor2[10];
    size_t tamanhoVetor = sizeof(vetor1) / sizeof(vetor1[0]);

    for(int i = 0; i < tamanhoVetor; i++) {
        vetor1[i] = rand() % 101;
        vetor2[i] = rand() % 101;
    };
    
	printf("\nVetor1 desordenado:\n");
	printarVetor(vetor1, tamanhoVetor);
	
    bubbleSort(vetor1, tamanhoVetor);

    printf("\nVetor1 ordenado por bubbleSort:\n");
	printarVetor(vetor1, tamanhoVetor);
    
    printf("\nVetor2 desordenado:\n");
    printarVetor(vetor2, tamanhoVetor);

    quickSort(vetor2, 0, tamanhoVetor - 1);

    printf("\nVetor2 ordenado por quickSort:\n");
    printarVetor(vetor2, tamanhoVetor);

    return 0;
}

