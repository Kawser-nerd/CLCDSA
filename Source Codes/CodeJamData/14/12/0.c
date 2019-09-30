#include<stdio.h>

struct node{
	int nchi,ndel;
	struct edge*next;
}nm[1000];

struct edge{
	struct node*dest;
	struct edge*next;
}emem[2000],*em;

void newedge(int b,int c){
	em->dest=nm+c;
	em->next=nm[b].next;
	nm[b].next=em;
	em++;
}

void dfs(struct node*t,struct node*parent){
	struct edge*p;
	int nedge;
	t->nchi=1;
	nedge=0;
	for(p=t->next;p!=NULL;p=p->next){
		if(p->dest==parent)continue;
		dfs(p->dest,t);
		t->nchi+=p->dest->nchi;
		nedge++;
	}
	if(nedge<=1){
		t->ndel=t->nchi-1;
		return;
	}
	if(nedge>=2){
		struct edge*q;
		int ndel2;
		t->ndel=1000000;
		for(p=t->next;p!=NULL;p=p->next){
			if(p->dest==parent)continue;
			for(q=p->next;q!=NULL;q=q->next){
				if(q->dest==parent)continue;
				ndel2=t->nchi-1-
				(p->dest->nchi+q->dest->nchi)+
				(p->dest->ndel+q->dest->ndel);
				if(t->ndel>ndel2)t->ndel=ndel2;
			}
		}
	}
}

int main(int argc,char*argv[]){
	int a,b,c,e,f,n;
	int ans;
	scanf("%d",&e);
	for(f=1;f<=e;f++){
		scanf("%d",&n);
		for(a=0;a<n;a++){
			nm[a].next=NULL;
		}
		em=emem;
		for(a=0;a<n-1;a++){
			scanf("%d%d",&b,&c);
			b--;
			c--;
			newedge(b,c);
			newedge(c,b);
		}
		ans=n;
		for(a=0;a<n;a++){
			dfs(nm+a,NULL);
			if(ans>nm[a].ndel)ans=nm[a].ndel;
		}
		printf("Case #%d: %d\n",f,ans);
	}
	return 0;
}
