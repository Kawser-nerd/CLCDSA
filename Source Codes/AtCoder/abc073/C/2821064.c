#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct integ{
   int  num;
   int  count;
   struct integ *left;
   struct integ *right;
};

void adder(int);
void liberty(struct integ *);
void avl();                    //????

struct integ *start,*int_point;
int checker=0;
int leftside=0;          //????
int rightside=0;

int ans=0;

int main(){
    char fig;
   start=(struct integ *)malloc(sizeof(struct integ));
    int N;
    scanf("%d",&N);
    int n;
    for(n=0;n<N;n++){
    	int k;
    	scanf("%d",&k);
    	adder(k);
    }
    
   liberty(start);//free??
  printf("%d\n",ans);
}

void  adder(int i){
  int o=0;
  if(checker==0){
    start->num=i;
    start->count=1;
    start->left=NULL;
    start->right=NULL;
    checker++;
  }else{
    int_point=start;
    struct integ *p;
   while(o==0){
//printf("%d %d",int_point->num,i);
    if(int_point->num > i){
 if(int_point==start){                 //????
 	leftside++;
 }
       if(int_point->left==NULL){
//printf("W");
          p=int_point;
          int_point=(struct integ *)malloc(sizeof(struct integ));
          p->left=int_point;
          int_point->num=i;
          int_point->count=1;
          int_point->left=NULL;
          int_point->right=NULL;
          o=1;
       }else{
//printf("D");
         int_point=int_point->left;
       }
    }else{
       if(int_point->num!=i){
       	if(int_point==start){                 //????
 	rightside++;
 }
      if(int_point->right==NULL){
//printf("A");
          p=int_point;
          int_point=(struct integ *)malloc(sizeof(struct integ));
          p->right=int_point;
          int_point->num=i;
          int_point->count=1;
          int_point->left=NULL;
          int_point->right=NULL;
          o=1;
       }else{
//printf("S");
         int_point=int_point->right;
       }
     }else{
     	int_point->count+=1;
        o=1;
        }
    }
   }//while
   }
   
   if(abs(leftside-rightside)>1){            //????
   	//avl();
   }
   
}


void  liberty(struct integ *here){
int i;
  if(checker==0){
    //printf("no element here.\n");
  }else{
if(here->right!=NULL){
liberty(here->right);
}
if(here->left!=NULL){
liberty(here->left);
}
if(here->count%2==1){
	ans++;
}

free(here);
  }

}



void avl(){
	struct integ *q;
	if(leftside<rightside){
		
		q=start;
     		int_point=start->right;
     		int flag1=0;
     		while(int_point->left!=NULL){
     			flag1=1;
     			q=int_point;
     			int_point=int_point->left;
     		}
     		
     		
     		if(flag1==0){
     			//int_point->right=(start->right)->right;
     			q->right=NULL;
     		}else{
     			
     			if(int_point->right!=NULL){
     		q->left=int_point->right;
     		}else{
     			q->left=NULL;
     		}
     			
     		int_point->right=start->right;
     		}
     		int_point->left=start;
     		start->right=NULL;
		    start=int_point;
		    leftside++;
		    rightside--;
	}else{
		
		q=start;
     		int_point=start->left;
     		int flag2=0;
     		while(int_point->right!=NULL){
     			flag2=1;
     			q=int_point;
     			int_point=int_point->left;
     		}
     		
  
     		if(flag2==0){
     		//	int_point->left=(start->left)->left;
     		q->left=NULL;
     		}else{
     			
     			   		if(int_point->left!=NULL){
     		q->right=int_point->left;
     		}else{
     			q->right=NULL;
     		}
     			
     		int_point->left=start->left;
     		}
     		int_point->right=start;
     		start->left=NULL;
		    start=int_point;
		leftside--;
		    rightside++;
		
	}
	
} ./Main.c: In function ‘main’:
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:31:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d",&k);
      ^