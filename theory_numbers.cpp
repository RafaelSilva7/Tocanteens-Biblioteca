#include <bits/stdc++.h>

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

/*
 * Apresenta todos os divisores de um numero n
*/
void print_divisor(int n){
	for (int i = 1; i <= sqrt(n); i++)
	{
		// i é divisor de n
		if (n%i == 0){
			// Verifica de i e n/i são iguais
			if (n/i == i)
				printf("%d ", i);
			else
				printf("%d %d ", i, n/i);
		}
	}
	cout << endl;
}

// Small Prime Factor  - Menor fator primo de um numero
#define MAX_PRIME 100001
int spf[MAX_PRIME];

/* Preenche o vetor spf
 * Complexidade O(n log(log n))
 */
void sieve(){
	// Inicialmente todo numero é considerado primo
	for (int i = 1; i < MAX_PRIME; i++)
		spf[i] = i;

	// Para numeros par o menor fator primo é 2
	for (int i=4; i < MAX_PRIME; i+=2)
		spf[i] = 2;

	for (int i=3; i*i < MAX_PRIME; i++){
		// Verifica se ele é primo
		if (spf[i] == i){
			// O atribui a todos os seus multiplos
			for (int j = i*i; j < MAX_PRIME; j+=i)
				// Verifica se ele ainda não foi previamente marcado
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

/* Vertorna um vector com os fatores primo, dividindo o numero pelo seu menor 
 * fator primo de forma sucessiva
 * Complexidade O(log n)
*/
vector<int> getFactorization(int x){
	vector<int> resp;
	while(x != 1){
		resp.push_back(spf[x]);
		x /= spf[x];
	}
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
	int x = 12563;
	cout << "Divisor de " << x << ":\n";
	print_divisor(x);

	return 0;
}