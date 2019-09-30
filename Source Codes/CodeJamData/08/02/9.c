#include <stdlib.h>
#include <stdio.h>

#define MAXNODE 200
#define STATION_A 1
#define STATION_B 2

typedef struct node{
	int station;
	int time[2];
} *Node;

Node Anodes[MAXNODE];
Node Bnodes[MAXNODE];
int n,t,na,nb;
int cases[MAXNODE][2] = {0};

void nodesort(Node *nodes,int flag){
	int i,j;
	Node p;
	int nn = na+nb;
	for(i=1;i<nn;i++){
		for(j=i+1;j<=nn;j++){
			if(nodes[j]->time[0]*60+nodes[j]->time[1] < nodes[i]->time[0]*60+nodes[i]->time[1]){
				p = nodes[j];
				nodes[j] = nodes[i];
				nodes[i] = p;
			}else if(flag == 1 && nodes[j]->time[0]*60+nodes[j]->time[1] == nodes[i]->time[0]*60+nodes[i]->time[1] && nodes[j]->station > nodes[i]->station){
				p = nodes[j];
				nodes[j] = nodes[i];
				nodes[i] = p;
			}else if(flag == 2 && nodes[j]->time[0]*60+nodes[j]->time[1] == nodes[i]->time[0]*60+nodes[i]->time[1] && nodes[j]->station < nodes[i]->station){
				p = nodes[j];
				nodes[j] = nodes[i];
				nodes[i] = p;
			}
		}
	}

}
/*int combine1(){
	int i,j,ok=1;
	int nn = na+nb;
	ok = 0;
	nodesort();
	for(i=1;i<=nn;i++){
		if(!nodes[i]->flag){
			for(j=1;j<=nn;j++){
				if(!nodes[j]->flag && nodes[i]->station != nodes[j]->station && i != j && nodes[i]->endtime[0]*60+nodes[i]->endtime[1] <= nodes[j]->starttime[0]*60+nodes[j]->starttime[1]){
					nodes[i]->endtime[1] = nodes[j]->endtime[1];
					nodes[i]->endtime[0] = nodes[j]->endtime[0];
					nodes[j]->flag = 1;
					ok = 1;
					return ok;
				}
			}
		}
	}
	return ok;
}

void combine(){
	int ok;
	while((ok = combine1()));	
}
*/
void main(){
	int i,j,count=0;
	int t1,t2;
	FILE * f = fopen("B-large.in","r");
	fscanf(f,"%d",&n);
	for(i=1;i<=n;i++){
		fscanf(f,"%d",&t);
		fscanf(f,"%d %d",&na,&nb);
		for(j=1;j<=na+nb;j++){
			Anodes[j] = malloc(sizeof(struct node));
			Bnodes[j] = malloc(sizeof(struct node));
			Anodes[j]->station = (j <= na) ? STATION_A : STATION_B;
			Bnodes[j]->station = (j <= na) ? STATION_A : STATION_B;
			if(j<=na){
				fscanf(f,"%d:%d %d:%d",&(Anodes[j]->time[0]),&(Anodes[j]->time[1]),&(Bnodes[j]->time[0]),&(Bnodes[j]->time[1]));
				t1 = Bnodes[j]->time[1] + t;
				t2 = Bnodes[j]->time[0] + t1 / 60;
				Bnodes[j]->time[0] = t2;
				Bnodes[j]->time[1] = t1%60;
			}
			else{
				fscanf(f,"%d:%d %d:%d",&(Bnodes[j]->time[0]),&(Bnodes[j]->time[1]),&(Anodes[j]->time[0]),&(Anodes[j]->time[1]));
				t1 = Anodes[j]->time[1] + t;
				t2 = Anodes[j]->time[0] + t1 / 60;
				Anodes[j]->time[0] = t2;
				Anodes[j]->time[1] = t1%60;
			}
		}
		//combine();
		nodesort(Anodes,1);
		nodesort(Bnodes,2);
		count = 0;
		for(j=1;j<=na+nb;j++){
			if(Anodes[j]->station == STATION_A){
				if(count <= 0)
					cases[i][0]++;
				else
					count = count <= 0 ? 0 : count-1;
			}
			else if(Anodes[j]->station == STATION_B)
				count++;
		}
		count = 0;
		for(j=1;j<=na+nb;j++){
			if(Bnodes[j]->station == STATION_B){
				if(count == 0)
					cases[i][1]++;
				else
					count = count <= 0 ? 0 : count-1;
			}
			else if(Bnodes[j]->station == STATION_A)
				count++;
		}

	}
	
	
	fclose(f);
	f = fopen("B-large.out","w");
	for(i=1;i <= n;i++){
		fprintf(f,"Case #%d: %d %d\n",i,cases[i][0],cases[i][1]);
	}
	fclose(f);

}
