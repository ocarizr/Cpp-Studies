#include <stdlib.h>
#include <iostream>
#include <new>

using namespace std;
int main()
{
	int tamanho, i;
	int* vetor;
	
	cout << "Digite o tamanho: ";
	cin >> tamanho;
	
	vetor = new int(tamanho);
	
	for(i = 0; i < tamanho; i++)
	{
		vetor[i] = i * i;
		printf("Vetor[%d] = %d\n", i, vetor[i]);
	}
	
	free(vetor);
	
	return 0;
}
