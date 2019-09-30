#include <stdio.h>
#include <stdlib.h>

int table[101][101];
int games[101];
int wins[101];
double avg_OWP[101];
double score[101];

double get_OWP(int opp, int is_win) {
  return ((double)(wins[opp]-is_win))/((double)(games[opp]-1));
} 



int main() {

  int T, N;

  scanf("%d", &T);
  
  int i, j, k;

  for(i=1; i<=T; i++) {

    printf("Case #%d:\n", i);

    scanf("%d", &N);

    char buffer[102];

    for(j=0; j<N; j++) {
      games[j] = 0;
      wins[j] = 0;
      avg_OWP[j] = 0.0;
      score[j] = 0.0;
      for(k=0; k<N; k++) 
	table[j][k] =-1;
    }
    
    for(j=0; j<N; j++) {
      scanf("%s", buffer);
      for(k=0; k<N; k++) {
	if(buffer[k]=='1') {
	  table[j][k] = 1;
	  wins[j]++;
	  games[j]++;
	}
	else if(buffer[k]=='0') {
	  table[j][k]=0;
	  games[j]++;
	}
      }
    }

    for(j=0; j<N; j++) {
      score[j] += 0.25 * ((double) wins[j])/((double) games[j]);
      for(k=0; k<N; k++) {
	if(table[j][k]!=-1) {
	  avg_OWP[j]+=(get_OWP(k, table[k][j])/((double)games[j]));
	}
      }
      score[j] += 0.50 * avg_OWP[j];
    }

    for(j=0; j<N; j++) 
      for(k=0; k<N; k++) 
	if(table[j][k]!=-1)
	   score[j]+=avg_OWP[k]/((double)games[j]) * 0.25;

    for(j=0; j<N; j++)
      printf("%.12lf\n", score[j]);

  }

  return 0;

}
