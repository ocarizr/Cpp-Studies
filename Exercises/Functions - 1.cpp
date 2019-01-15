#include <stdlib.h>
#include <iostream>

// Exercício de uso de funções
// Existem melhores praticas para executar as funções do programa
// O objetivo é apenas usar funções para qualquer fim

using namespace std;

int sqr(int iValue);
int sum(int a, int b);
bool greater(int a, int b);

int main()
{
	// Declaração das variáveis
	int iVal1, iVal2;
	
	// Input do usuário
	cout << "Insira o primeiro valor: ";
	cin >> iVal1;
	cout << "Insira o segundo valor: ";
	cin >> iVal2;
	
	// testa a função sqr
	cout << "O quadrado de " << iVal1 << " eh: " << sqr(iVal1) << endl;
	cout << "O quadrado de " << iVal2 << " eh: " << sqr(iVal2) << endl;
	
	// testa a função sum
	cout << "A soma " << iVal1 << " + " << iVal2 << " = " << sum(iVal1, iVal2) << endl;
	
	// Testa a função greater
	if (greater(iVal1, iVal2))
	{
		cout << iVal1 << " eh maior que " << iVal2 << endl;
	} else
	{
		cout << iVal1 << " eh menor que " << iVal2 << endl;
	}
	
	// Pausa a execução do programa
	system("pause");
	
	return 0;
}

int sqr(int iValue)
{
	return (iValue * iValue);
}

int sum(int a, int b)
{
	return (a + b);
}

bool greater(int a, int b)
{
	if (a > b)
	{
		return true;
	}
	
	return false;
}
