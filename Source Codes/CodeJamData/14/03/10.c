#include<stdio.h>
#include<stdlib.h>

int main(void){
  int t,p,i,j,k,r,c,m,tmp,flg;
  char map[50][51];
  scanf("%d",&t);
  for(p=1;p<=t;p++){
    flg=0;
    scanf("%d%d%d",&r,&c,&m);
    tmp=r*c-m;
    //R==1 or C==1
    // printf("%d %d %d\n",r,c,m);
    if(r==1 || c==1){
      //puts("rc1:");
      //tmp==1 -> false
      
      for(i=0;i<r;i++){
	for(j=0;j<c;j++){
	  if(m){
	    m--;
	    map[i][j]='*';
	  }else{
	    map[i][j]='.';
	  }
	}
      }
      map[r-1][c-1]='c';
      flg=1;
      
      //R>1 & C>1
    }else{
      //puts("other");
      //R*C-M==1,2, or 3
      if(1<tmp && tmp<4){
	printf("Case #%d:\nImpossible\n",p);
	continue;
	//tmp>4
      }else if(tmp==1){
	for(i=0;i<r;i++){
	  for(j=0;j<c;j++){
	    if(!i && !j) map[i][j]='c';
	    else map[i][j]='*';
	  }
	}
	flg=1;
      }else{
	//printf("r*c-m:%d\n",tmp);
	for(i=c;i>=2 && (tmp/i<r || (tmp/i==r && tmp%i==0)) && !flg;i--){
	  //最低でも地雷なしがi個あるラインが2行は必要
	  if(tmp<2*i) continue;
	  //一番下のラインの地雷でない部分の個数が1以外
	  if(tmp%i!=1){
	    //printf("tmp/c:%d\n",tmp/i);
	    for(j=0;j<r;j++){
	      for(k=0;k<c;k++){
		if(j<tmp/i){
		  if(k<i) map[j][k]='.';
		  else map[j][k]='*';
		}else if(j==tmp/i){
		  if(k<tmp%i) map[j][k]='.';
		  else map[j][k]='*';
		}else map[j][k]='*';
	      }
	    }
	    flg=1;
	    //地雷なしがi個のラインが3つ以上ある場合は、1つを下のラインに繰り越すことでクリア
	  }else if(tmp/i>=3 && i>2){
	    //printf("tmp/i,:%d\n",tmp/i);

	    for(j=0;j<r;j++){
	      for(k=0;k<c;k++){
		if(j<tmp/i-1){
		  if(k<i) map[j][k]='.';
		  else map[j][k]='*';
		}else if(j==tmp/i-1){
		  if(k<i-1) map[j][k]='.';
		  else map[j][k]='*';
		}else if(j==tmp/i){
		  if(k<2) map[j][k]='.';
		  else map[j][k]='*';
		}else map[j][k]='*';
	      }
	    }
	    flg=1;
	  }
	}
      }
      map[0][0]='c';
    }
    printf("Case #%d:\n",p);
    if(!flg) puts("Impossible");
    else{
      for(i=0;i<r;i++){
	for(j=0;j<c;j++){
	  printf("%c",map[i][j]);
	  if(j==c-1) putchar('\n');
	}
      }
    }
  }
  return 0;
}
	
	    
