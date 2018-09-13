#include <iostream>

using namespace std;

/* GCD - Maior Divisor Comum
 * return: Retorna o maior dividor comum de dois numeros
*/
int gcd(int a, int b){
	if (b==0)
		return a;
	return gcd(b,a%b);
}


/* LCM - Minimo Multiplo Comum
 * return: Retorna o minimo multiplo comum de dois numeros
*/
int lcm(int a, int b){
	// Aplicação do algoritmo Euclidean
	return (a*b)/gcd(a,b);
}

/* Função retorna o LCM de um array de inteiros
 * arr[]: array sobre o qual será calculado o LCM
 * n: tamanho do array
*/
int find_lcm(int arr[], int n){
	// Inicializa a varial de resposta
	int ans = arr[0];
	// Processo iterativo para o calculo do lcm
	for (int i = 1; i < n; i++)
		ans = (ans * arr[i])/gcd(ans,arr[i]);

	return ans;
}


/* Funão retorna o GCD de um array de inteiros
 * arr[]: array sobre o qual será calculado GCD
 * n: tamanho do array
*/
int find_gcd(int arr[], int n){
	int ans = arr[0];
	for (int i = 1; i < n; i++)
		ans = gcd(arr[i], ans);
	return ans;
}

int main(int argc, char const *argv[])
{
	int a = 36, b = 60;
	cout << "GCD = " << gcd(a,b) << endl;
	a = 15; b = 25;
	cout << "LCM = " << lcm(a,b) << endl;

	int arr[] = { 2, 4, 6, 8, 16 }, n = sizeof(arr)/sizeof(arr[0]);
	cout << "LCM Array = " << find_lcm(arr,n) << endl;
	cout << "GCD Array = " << find_gcd(arr,n) << endl;
	return 0;
}