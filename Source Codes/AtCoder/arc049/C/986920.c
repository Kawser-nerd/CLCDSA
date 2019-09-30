#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <regex.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define alloc(type,size) calloc(sizeof(type),size)

int res;

typedef struct node {
	struct branch {
		struct branch *side;
		struct node *below;
	} *xy;
	struct branch *vu;
	bool bl;
	bool notuse;

} node;
typedef struct branch branch;

branch* push_back_xy(node *a,node *b,branch *c){
	c->side = a->xy;
	c->below = b;
	a->xy = c;
	return ++c;
}
branch* push_back_vu(node *a,node *b,branch *c){
	c->side = a->vu;
	c->below = b;
	a->vu = c;
	return ++c;
}

bool can_paint(node *nd){
	branch *br;
	for(br=nd->xy;br;br=br->side) if(!br->below->bl) return false;
	for(br=nd->vu;br;br=br->side) if(!br->below->bl && !br->below->notuse) return false;
	return true;	
}

bool paint(node *nd){
	if(!can_paint(nd)) return false;
	nd->bl = true;
	return true;
}


void nurima_su(node *nd,int n){
	int f = 0;
	int i = 0;
	do{
		if(!nd[i].bl && !nd[i].notuse){
			if(paint(&nd[i])){
				res++;
				f=i;
			}
		}
		i = (i + 1) % n;
	}while(f!=i);
	return;

}



int main(void){
	int n,a,b;
	int x,y;
	int u,v;

	node* nd;
	node** bs;
	branch* br;
	int i,j,k;
	int bits;
	int ret = 0;

	scanf("%d",&n);
	nd = alloc(node,n);
	nd--;//1 origin
	scanf("%d",&a);
	br = alloc(branch,a);
	for(i=0;i<a;i++){
		scanf("%d%d",&x,&y);
		br = push_back_xy(&nd[x],&nd[y],br);
	}
	scanf("%d",&b);
	br = alloc(branch,b);
	bs = alloc(node*,b);
	for(i=0;i<b;i++){
		scanf("%d%d",&x,&y);
		br = push_back_vu(&nd[y],&nd[x],br);
		bs[i] = &nd[x];
	}
	nd++;//0 origin
	bits = 1 << b;
	for(i=0;i<bits;i++){
		for(j=0;j<n;j++){
			nd[j].bl = false;
		}
		res = 0;		
		for(j=1,k=0;j<bits;j=j<<1,k++){
			bs[k]->notuse = false;
			if(i&j) bs[k]->notuse = true;
		}
		nurima_su(nd,n);
		ret = max(ret,res);

	}

	printf("%d\n", ret);





    return 0;
} ./Main.c: In function ‘main’:
./Main.c:86:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:89:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^
./Main.c:92:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^
./Main.c:95:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&b);
  ^
./Main.c:99:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^