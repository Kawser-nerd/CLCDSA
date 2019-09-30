#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define pb push_back
#define fori(i, n) for (i = 0; i < (n); i++ )
#define forr(i, a, b) for ( int i = (a); i <= (b); i++ )
#define size(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define sorting(x) sort(all(x))
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end()
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define print_m(m) for(int i = 0;i<(int) m.size();i++) print_v(m[i]); cout << endl;
#define print_v(v) { for(int j = 0;j<(int) v.size();j++) cout << v[j] << " "; cout << endl; }
#define trace(x...)
#define PRINT(x...) trace(printf(x))
#define watch(x) trace(cout << #x " = " << x << "\n")

#define GRANDE 6000

const int INF = 0x3FFFFFFF;
const double EPS = 1e-10;
const double PI = 3.14159265;
const double EXP = 2.71828183;

int alfabeto[1000];
int main()
{
	int N, teste, i;
	char number[62];
	scanf("%d\n", &N);
	for(teste=1; teste<=N; teste++){
		scanf("%s\n", number);
		PRINT("N: %s\n", number);
		fori(i,1000) alfabeto[i] = -1;
		
		//traduz de char p/ int.
		alfabeto[number[0]] = 1;
		//atribui o "0"
		int len = strlen(number);
		fori(i, len){
			if(alfabeto[number[i]] == -1){	//if not found yet
				alfabeto[number[i]] = 0;
				break;
			}
		}
		//atribui os demais
		int available = 2;

		fori(i, len){
			if(alfabeto[number[i]] == -1){	//if not found yet
				alfabeto[number[i]] = available++;
			}
		}
		//ao final, available == base
		unsigned long long int soma = 0;
		unsigned long long int aux;
		unsigned long long int b = 1;
		int base = available;
		for(i=len-1; i>=0; i--){
			aux = (unsigned long long int) alfabeto[number[i]];
			soma = soma + aux*b;
			b = (unsigned long long int) b * base;
			if(soma < 0){
				printf("Erro!\n");
			}
		}
		
		//print
		char digit;
		PRINT("Number in base %d - %d\n", available, soma);
		fori(i, len){
			digit = alfabeto[number[i]];
			if(digit < 10) digit += '0';
			else digit += 'A';
			PRINT("%c ",digit);
		}
		PRINT("\n");
		
		printf("Case #%d: %lld\n",teste, soma);
	}
	return 0;
}