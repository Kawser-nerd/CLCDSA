#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000


typedef struct dec{
	
	double wt;
	char feat[MAX];
	struct dec *left;	
	struct dec *right;
	}dec;

	
double cuteness(dec *start,char feat[][MAX],int n){

	int i;
	int fg=0;	
	
	if(start-> left== NULL && start-> right==NULL)
	 return(start->wt);	

	for(i=0;i<n;i++){
	  	if(strcmp(start->feat,feat[i])==0)
		  fg=1;	
	}
		
	// fg=1 means left
	// else right
		
	if(fg)	
	 return((start->wt)*cuteness(start->left,feat,n)); 
	else
	 return((start->wt)*cuteness(start->right,feat,n)); 	

}

dec *read_input(){
	
	char ch,feat[MAX],buf[MAX];
	double wt;
	dec *start;
	int i;

	start=(dec *)malloc(sizeof(dec));	
		
	ch=getchar();
	while(ch!='(')
	 ch=getchar();	
	
	scanf("%lf",&wt);
	start-> wt= wt;

	ch=getchar();
	while(ch==' ')
	 ch=getchar();

	if(ch==')'){
		start-> left=NULL;
		start-> right=NULL; 

		return(start); 
	}
	
	i=0;
	while(ch>='a' && ch <= 'z'){

	  start->feat[i++]= ch;
	  ch=getchar();		  		
	}
	start->feat[i]='\0'; 
	 
	start-> left = read_input();
	start-> right = read_input();

	ch=getchar();
	while(ch!=')')
	 ch=getchar();
	
	return(start);
}


int main(){
	
	int N,i,L,A,j,n,k;
	char anim[MAX],feat[200][MAX];
	dec *start;

	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		
		scanf("%d",&L);	
			
		start= read_input();

		scanf("%d",&A);
		
		printf("Case #%d:\n",i+1);
		for(j=0;j<A;j++){
			scanf("%s %d",anim,&n);
			for(k=0;k<n;k++)	
				scanf("%s",feat[k]);

			printf("%0.8lf\n",cuteness(start,feat,n));
				
		}
		free(start);					
	}

}



