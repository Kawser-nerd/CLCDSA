#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int nb[500], ncount, visited;
} Node; 

Node planets[500];
int T, P, W;
int minSteps, maxThreaten;

void add_edge(int a, int b) {
  planets[a].nb[planets[a].ncount++] = b;
  planets[b].nb[planets[b].ncount++] = a;
}

int numThreaten() {
  int flags[500] = {0};

  int i, j;

  for(i=0; i<P; i++) {
    if(planets[i].visited) {
      for(j=0; j<planets[i].ncount; j++) {
	int k = planets[i].nb[j];
	if(!planets[k].visited)
	  flags[k] = 1;
      }
    }
  }

  int ans = 0;

  for(i=0; i<P; i++) 
    ans += flags[i];

  return ans;

}

void search(int index, int steps) {
  if(steps>minSteps)
    return;
  int i;

  for(i=0; i<planets[index].ncount; i++) {
    int j = planets[index].nb[i];
    if(j==1) {
      int t = numThreaten();
      if(steps<minSteps) {
	minSteps = steps;
	maxThreaten = t;
      }
      else if(steps==minSteps) {
	if(t>maxThreaten)
	  maxThreaten = t;
      }
      
    }
    if(planets[j].visited==0) {
      planets[j].visited = 1;
      search(j,steps+1);
      planets[j].visited = 0;
    }
  }
}

int main() {
  
  int i, j;

  scanf("%d", &T);

  for(i=1; i<=T; i++) {
    scanf("%d %d", &P, &W);
    for(j=0; j<P; j++) {
      planets[j].ncount = 0;
      planets[j].visited = 0;
    }
    for(j=0; j<W; j++) {
      int a,b;
      scanf("%d,%d", &a, &b);
      add_edge(a,b);
    }
    planets[0].visited = 1;
    minSteps = 10000;
    maxThreaten = -1;
    search(0, 0);
    
    printf("Case #%d: %d %d\n", i, minSteps, maxThreaten);

  }
  
  return 0;

}
