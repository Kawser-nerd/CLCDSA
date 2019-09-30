#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
char inputS[3000];
int countN[20];
int countA[130];
int i, x, y, c, L;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		scanf("%s", inputS);
		L = strlen(inputS);
		memset(countN, 0, sizeof(countN));
		memset(countA, 0, sizeof(countA));
		
		for (i=0; i<L; i++) countA[inputS[i]]++;
		
		c = countA['X'];
		countN[6] += c;
		countA['S'] -= c; countA['I'] -= c; countA['X'] -= c;
		
		c = countA['Z'];
		countN[0] += c;
		countA['Z'] -= c; countA['E'] -= c; countA['R'] -= c; countA['O'] -= c;
		
		c = countA['S'];
		countN[7] += c;
		countA['S'] -= c; countA['E'] -= c; countA['V'] -= c; countA['E'] -= c; countA['N'] -= c;
		
		c = countA['U'];
		countN[4] += c;
		countA['F'] -= c; countA['O'] -= c; countA['U'] -= c; countA['R'] -= c;
		
		c = countA['V'];
		countN[5] += c;
		countA['F'] -= c; countA['I'] -= c; countA['V'] -= c; countA['E'] -= c;
		
		c = countA['G'];
		countN[8] += c;
		countA['E'] -= c; countA['I'] -= c; countA['G'] -= c; countA['H'] -= c; countA['T'] -= c;
		
		c = countA['R'];
		countN[3] += c;
		countA['T'] -= c; countA['H'] -= c; countA['R'] -= c; countA['E'] -= c; countA['E'] -= c;
		
		c = countA['I'];
		countN[9] += c;
		countA['N'] -= c; countA['I'] -= c; countA['N'] -= c; countA['E'] -= c;
		
		c = countA['T'];
		countN[2] += c;
		countA['T'] -= c; countA['W'] -= c; countA['O'] -= c;
		
		c = countA['O'];
		countN[1] += c;
		countA['O'] -= c; countA['N'] -= c; countA['E'] -= c;
		
		for (i=0; i<10; i++) for (x=0; x<countN[i]; x++) printf("%d", i);
		puts("");
		
	}
	
	
	return 0;
}


