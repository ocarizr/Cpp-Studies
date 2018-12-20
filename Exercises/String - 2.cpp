#include <stdlib.h>
#include <iostream>
#include <string>

// O uso de namespace facilita na digitação do código
// deve-se usar com muita cautela
using namespace std;

// Código para fazer input de strings no sistema
// Este código reconhece espaço entre as palavras
// Este programa é uma otimização do String - 1 utilizando C++
int main()
{
	// Declaração da variável que irá alocar a string
	string sPalavra;
	
	// Imprime instrução ao usuário
	cout << "Digite uma palavra: ";
	
	// Solicita input do texto pelo usuário
	// Usa o getline para poder reconhecer os espaços entre as palavras
	getline (cin, sPalavra);
	
	// Imprime a palavra digitada
	cout << "A palavra digitada eh: " << sPalavra << endl;
	
	// Para a execução do sistema
	system("pause");
	
	// Como a função principal é do tipo int (limitação do C++) deve-se retornar algo
	return 0;
}
