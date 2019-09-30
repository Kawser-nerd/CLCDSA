#include<stdio.h>
#define inf 1072114514
#define size 262144

typedef struct{
int stv;
int fiv;
int cost;
}data;

data heap[size];
int hsize=0;

void resheap(){
    int i;
    heap[0].cost=-inf;
    for(i=1;i<size;i++){
        heap[i].cost=inf;
    }
}

int swjud(data high,data low){
    if(high.cost > low.cost){return 1;}
    return -1;
}

void pqpush(data x){
    int a,b;
    data m;
    hsize++;
    heap[hsize]=x;
    a=hsize;
    while(1){
        b=a/2;
        if(swjud(heap[b],heap[a]) == 1){
            m=heap[a];heap[a]=heap[b];heap[b]=m;
        }
        else{break;}
        a=b;
    }
}

data pqpop(){
    int a,b,c;
    data m,sw;
    m=heap[1];
    heap[1]=heap[hsize];
    heap[hsize].cost=inf;
    hsize--;
    a=1;
    while(1){
        b=a*2;c=a*2+1;
        if(swjud(heap[a],heap[b])==-1 && swjud(heap[a],heap[c])==-1){break;}
        if(swjud(heap[b],heap[c])==-1){
            sw=heap[a];heap[a]=heap[b];heap[b]=sw;
            a=b;
        }
        else{
            sw=heap[a];heap[a]=heap[c];heap[c]=sw;
            a=c;
        }
    }
    return m;
}

void prarr(int arr[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i){printf(" ");}
    printf("%d",arr[i]);
  }
  printf("\n");
  return;
}

typedef struct{
int val;
int node;
}segd;

int ssize=size;
segd vd;

void sinit(segd stree[]){
    vd.val=inf;
    vd.node=-1;
    int i,j;
    for(i=0;i<2*ssize;i++){
        stree[i].val=inf;
        stree[i].node=-1;
    }
}

void upd(segd stree[],int k,segd a){
    int i,m;
    segd ld,rd,md;
    k+=ssize-1;
    stree[k]=a;
    while(k>0){
        k=(k-1)/2;
        ld=stree[2*k+1];
        rd=stree[2*k+2];
        if(ld.val<rd.val){md=ld;}
        else{md=rd;}
        stree[k]=md;
    }
}

//calc min[a,b)
//call:k=0,l=0,r=ssize
segd query(segd stree[],int a,int b,int k,int l,int r){
    segd ld,rd;
    if(r<=a || b<=l){return vd;}
    if(a<=l && r<=b){
        return stree[k];
    }
    else{
        ld=query(stree,a,b,k*2+1,l,(l+r)/2);
        rd=query(stree,a,b,k*2+2,(l+r)/2,r);
        if(ld.val<rd.val){return ld;}
        else{return rd;}
    }
}

int n;
int a[size];
segd seg[2][2*size];
int res[size];

int main(void){
    resheap();
    int i,j,m,k,b,c,h,w,r=0,l,t,pt=0,p;
    int st,fi;
    segd spd;
    segd fm,sm,pp;
    data pd,od;
    sinit(seg[0]);
    sinit(seg[1]);
    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&a[i]);
      if(i%2==0){
        spd.val=a[i];
        spd.node=i;
        upd(seg[0],i,spd);
        spd.val=inf;
        upd(seg[1],i,spd);
      }
      else{
        spd.val=a[i];
        spd.node=i;
        upd(seg[1],i,spd);
        spd.val=inf;
        upd(seg[0],i,spd);
      }
    }
    pd.stv=0;
    pd.fiv=n-1;
    pd.cost=1;
    pqpush(pd);
    while(hsize>0){
      od=pqpop();
      st=od.stv;
      fi=od.fiv;
      if(fi-st==2){
        res[pt]=a[st];
        res[pt+1]=a[st+1];
        pt+=2;
        continue;
      }
      w=st%2;
      fm=query(seg[w],st,fi+1,0,0,ssize);
      p=fm.node;
      w=1-w;
      sm=query(seg[w],p+1,fi+1,0,0,ssize);
      res[pt]=fm.val;
      res[pt+1]=sm.val;
      pt+=2;
      if(st<fm.node-1){
        pd.stv=st;
        pd.fiv=fm.node-1;
        pp=query(seg[(pd.stv)%2],pd.stv,pd.fiv+1,0,0,ssize);
        pd.cost=pp.val;
        pqpush(pd);
      }
      if(fm.node+1<sm.node-1){
        pd.stv=fm.node+1;
        pd.fiv=sm.node-1;
        pp=query(seg[(pd.stv)%2],pd.stv,pd.fiv+1,0,0,ssize);
        pd.cost=pp.val;
        pqpush(pd);
      }
      if(sm.node+1<fi){
        pd.stv=sm.node+1;
        pd.fiv=fi;
        pp=query(seg[(pd.stv)%2],pd.stv,pd.fiv+1,0,0,ssize);
        pd.cost=pp.val;
        pqpush(pd);
      }
    }
    prarr(res,n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:139:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:141:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a[i]);
       ^