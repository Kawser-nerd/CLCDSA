#include <stdio.h>
#include <stdlib.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
#define LEFT 0
#define RIGHT 1

typedef struct NODE{
	struct NODE *right;
	struct NODE *left;
	int data;
	int balance;
} Node;
typedef struct LIST{
	Node *node;
	int dir;
	struct LIST *next; 
} List;
List* add(List *l,Node *n,int d){
	List *tmp=(List*)malloc(sizeof(List));
	tmp->node=n; tmp->dir=d; tmp->next=l;
	return tmp;
}
void delete_list(List *l){
	List *tmp;
	while(l!=NULL){
		tmp=l;
		l=l->next;
		free(tmp);
	}
	return;
}
Node* make_node(int a){
	Node *n=(Node*)malloc(sizeof(Node));
	n->left=n->right=NULL;
	n->balance=0;
	n->data=a;
	return n;
}
Node *rotate_right(Node *node){
	Node *lnode = node->left;
	node->left = lnode->right;
	lnode->right = node;
	return lnode;
}
Node *rotate_left(Node *node){
	Node *rnode = node->right;
	node->right = rnode->left;
	rnode->left = node;
	return rnode;
}
void update_balance(Node *node){
	if(node->balance == 1){
		node->right->balance = -1;
		node->left->balance = 0;
	}
	else if(node->balance == -1){
		node->right->balance = 0;
		node->left->balance = 1;
	}
	else{
		node->right->balance = 0;
		node->left->balance = 0;
	}
	node->balance = 0;
	return;
}
Node *check_balance(Node *root,List *l){
	Node *new_node=NULL,*pnode,*gnode;
	int b,d,gdir;
	while(l!=NULL){
		pnode=l->node;
		d=l->dir;
		l=l->next;
		if(d==LEFT) pnode->balance++;
		else pnode->balance--;
		b=pnode->balance;
		if(b==0) return root;
		if(b>1){
			if(pnode->left->balance<0){
				pnode->left=rotate_left(pnode->left);
				new_node=rotate_right(pnode);
				update_balance(new_node);
			}
			else{
				new_node=rotate_right(pnode);
				new_node->balance=0;
				pnode->balance=0;
			}
			break;
		}
		else if(b<-1){
			if(pnode->right->balance>0){
				pnode->right=rotate_right(pnode->right);
				new_node=rotate_left(pnode);
				update_balance(new_node);
			}
			else{
				new_node=rotate_left(pnode);
				new_node->balance = 0;
				pnode->balance = 0;
			}
			break;
		}
	}
	if(l!=NULL){
		gnode=l->node;
		gdir=l->dir;
		if(gdir==LEFT) gnode->left = new_node;
		else gnode->right = new_node;
	}
	else if(new_node!=NULL) return new_node;
	return root;
}
Node *insert(Node *root,int a){
	List *l=NULL;
	Node *node,*res;
	if(root==NULL) return make_node(a);
	node=root;
	while(1){
		if(node->data==a) return root;
		else if(a<node->data){
			l=add(l,node,LEFT);
			if(node->left==NULL){
				node->left=make_node(a);
				break;
			}
			node=node->left;
		}
		else{
			l=add(l,node,RIGHT);
			if(node->right==NULL){
				node->right=make_node(a);
				break;
			}
			node=node->right;
		}
	}
	res=check_balance(root,l);
	delete_list(l);
	return res;
}
int find(Node *n,int a){
	if(n==NULL) return 0;
	if(n->data==a) return 1;
	if(n->data<a) return find(n->right,a);
	else return find(n->left,a);
}
void delete_tree(Node *n){
	while(n!=NULL){
		delete_tree(n->left);
		delete_tree(n->right);
		free(n);
	}
	return;
}
int a[100000];
int main(void){
	int n,res=0,i;
	Node *k=NULL;
	scanf("%d",&n);
	FOR(i,0,n){
		scanf("%d",&a[i]);
		if(i%2) k=insert(k,a[i]);
	}
	qsort(a,n,sizeof(int),comp);
	for(i=0;i<n;i+=2){
		if(find(k,a[i])) res++;
	}
	printf("%d\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:168:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:170:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^