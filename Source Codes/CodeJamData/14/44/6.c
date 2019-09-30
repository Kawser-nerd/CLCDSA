#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
int Strings, Servers;
char String[10][20];
char Visited[10];
char InServer[1000][20];
char Input[20];
int SIS[10];//StringInServer
int i, x, y, c, t, AnsNodes, AnsWays, Ans;

int QS(char A[], char B[]){
	return strcmp(A, B);
}

void DFS(int Level){
	if (Level==Strings){
		int i;
		memset(Visited, 0, sizeof(Visited));
		for (i=0; i<Strings; i++) Visited[SIS[i]] = 1;
		for (i=0; i<Servers; i++) if (!Visited[i]) return;
		
		Ans = 0;
		for (i=0; i<Servers; i++){
			c = 0;
			for (x=0; x<Strings; x++) if (SIS[x]==i){
				strcpy(Input, String[x]);
				for (t=strlen(Input); t>=0; t--){
					Input[t] = 0;
					strcpy(InServer[c], Input);
					c++;
				}
			}
			
			qsort(InServer, c, sizeof(InServer[0]), QS);
//printf("c %d ", c);
//for (t=0; t<c; t++) printf("S%s ", InServer[t]);
			Ans++;
			for (t=1; t<c; t++) if (strcmp(InServer[t-1], InServer[t])) Ans++;
		}
		
		if (Ans>AnsNodes){
			AnsNodes = Ans;
			AnsWays = 1;
			return ;
		}
		if (Ans==AnsNodes){
			AnsWays++;
			return ;
		}
		
		
		return ;
	}
	
	int i;
	for (i=0; i<Servers; i++){
		SIS[Level] = i;
		DFS(Level+1);
	}
	
}

int main(){
	freopen("D-small-attempt2.in", "r", stdin);
	freopen("D-small-attempt2.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		
		scanf("%d%d", &Strings, &Servers);
		
		for (i=0; i<Strings; i++) scanf("%s", String[i]);
		
		AnsNodes = 0;
		AnsWays = 0;
		
		DFS(0);
		
		printf("%d %d\n", AnsNodes, AnsWays);
	}
	
	return 0;
}

