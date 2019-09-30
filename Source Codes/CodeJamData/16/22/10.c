#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MIN(x,y) (((x)<(y))?(x):(y))

typedef unsigned long long ull;

void solve(void);

int main(void){
  int T,tt;
  scanf("%d%*c",&T);
  for(tt=1;tt<=T;tt++){
    printf("Case #%d: ",tt);
    solve();
  }
  return 0;
}

void solve(void){
  char str[2][20]={"",""},sma[2][20]={"",""},laa[2][20]={"",""};
  char smb[2][20]={"",""},lab[2][20]={"",""};
  int i,j,k,l,mval;
  ull num[4],tmp[2],mins,mintmp[2];
  bool smalla=false,smallb=false,largea=false,largeb=false,minflg;
  int minnum=0;

  scanf("%s%*c%s%*c",str[0],str[1]);
  l=strlen(str[0]);

  //a-small
  for(i=0;i<l;i++){
    if(!smalla){
      if(str[0][i]=='?' && str[1][i]=='?') sma[0][i]=sma[1][i]='0';
      else if(isdigit(str[0][i]) && isdigit(str[1][i])){
	sma[0][i]=str[0][i];
	sma[1][i]=str[1][i];
	if(sma[0][i]>sma[1][i]){
	  for(j=i-1;j>=0;j--){
	    if(sma[0][j]!='0' && str[0][j]=='?'){
	      sma[0][j]--;
	      smalla=true;
	      i=j;
	      break;
	    }
	  }
	}else if(sma[0][i]<sma[1][i]){
	  smalla=true;
	}
      }else{
	if(str[0][i]=='?') sma[0][i]=sma[1][i]=str[1][i];
	else sma[0][i]=sma[1][i]=str[0][i];
      }
    }else{
      if(str[0][i]=='?'){
	sma[0][i]='9';
      }else{
	sma[0][i]=str[0][i];
      }
      if(str[1][i]=='?'){
	sma[1][i]='0';
      }else{
	sma[1][i]=str[1][i];
      }
    }
    tmp[0]=strtoull(sma[0],NULL,10);
    tmp[1]=strtoull(sma[1],NULL,10);
    if(tmp[0]<tmp[1]) num[0]=tmp[1]-tmp[0];
    else num[0]=tmp[0]-tmp[1];
  }

  //a-large
  for(i=0;i<l;i++){
    if(!largea){
      if(str[0][i]=='?' && str[1][i]=='?') laa[0][i]=laa[1][i]='0';
      else if(isdigit(str[0][i]) && isdigit(str[1][i])){
	laa[0][i]=str[0][i];
	laa[1][i]=str[1][i];
	if(laa[0][i]<laa[1][i]){
	  for(j=i-1;j>=0;j--){
	    if(laa[0][j]!='9' && str[0][j]=='?'){
	      laa[0][j]++;
	      largea=true;
	      i=j;
	      break;
	    }
	  }
	}else if(laa[0][i]>laa[1][i]){
	  largea=true;
	}
      }else{
	if(str[0][i]=='?') laa[0][i]=laa[1][i]=str[1][i];
	else laa[0][i]=laa[1][i]=str[0][i];
      }
    }else{
      if(str[0][i]=='?'){
	laa[0][i]='0';
      }else{
	laa[0][i]=str[0][i];
      }
      if(str[1][i]=='?'){
	laa[1][i]='9';
      }else{
	laa[1][i]=str[1][i];
      }
    }
    tmp[0]=strtoull(laa[0],NULL,10);
    tmp[1]=strtoull(laa[1],NULL,10);
    if(tmp[0]<tmp[1]) num[1]=tmp[1]-tmp[0];
    else num[1]=tmp[0]-tmp[1];
  }

  //b-small
  for(i=0;i<l;i++){
    if(!smallb){
      if(str[0][i]=='?' && str[1][i]=='?') smb[0][i]=smb[1][i]='0';
      else if(isdigit(str[0][i]) && isdigit(str[1][i])){
	smb[0][i]=str[0][i];
	smb[1][i]=str[1][i];
	if(smb[0][i]>smb[1][i]){
	  for(j=i-1;j>=0;j--){
	    if(smb[1][j]!='9' && str[1][j]=='?'){
	      smb[1][j]++;
	      smallb=true;
	      i=j;
	      break;
	    }
	  }
	}else if(smb[0][i]<smb[1][i]){
	  smallb=true;
	}
      }else{
	if(str[0][i]=='?') smb[0][i]=smb[1][i]=str[1][i];
	else smb[0][i]=smb[1][i]=str[0][i];
      }
    }else{
      if(str[0][i]=='?'){
	smb[0][i]='9';
      }else{
	smb[0][i]=str[0][i];
      }
      if(str[1][i]=='?'){
	smb[1][i]='0';
      }else{
	smb[1][i]=str[1][i];
      }
    }
    tmp[0]=strtoull(smb[0],NULL,10);
    tmp[1]=strtoull(smb[1],NULL,10);
    if(tmp[0]<tmp[1]) num[2]=tmp[1]-tmp[0];
    else num[2]=tmp[0]-tmp[1];
  }

  //b-large
  for(i=0;i<l;i++){
    if(!largeb){
      if(str[0][i]=='?' && str[1][i]=='?') lab[0][i]=lab[1][i]='0';
      else if(isdigit(str[0][i]) && isdigit(str[1][i])){
	lab[0][i]=str[0][i];
	lab[1][i]=str[1][i];
	if(lab[0][i]<lab[1][i]){
	  for(j=i-1;j>=0;j--){
	    if(lab[1][j]!='0' && str[1][j]=='?'){
	      lab[1][j]--;
	      largeb=true;
	      i=j;
	      break;
	    }
	  }
	}else if(lab[0][i]>lab[1][i]){
	  largeb=true;
	}
      }else{
	if(str[0][i]=='?') lab[0][i]=lab[1][i]=str[1][i];
	else lab[0][i]=lab[1][i]=str[0][i];
      }
    }else{
      if(str[0][i]=='?'){
	lab[0][i]='0';
      }else{
	lab[0][i]=str[0][i];
      }
      if(str[1][i]=='?'){
	lab[1][i]='9';
      }else{
	lab[1][i]=str[1][i];
      }
    }
    tmp[0]=strtoull(lab[0],NULL,10);
    tmp[1]=strtoull(lab[1],NULL,10);
    if(tmp[0]<tmp[1]) num[3]=tmp[1]-tmp[0];
    else num[3]=tmp[0]-tmp[1];
  }

  mins=MIN(MIN(num[0],num[1]),MIN(num[2],num[3]));

  for(i=0;i<4;i++) minnum+=num[i]==mins;

  if(minnum==1){
    if(num[0]==mins) printf("%s %s\n",sma[0],sma[1]);
    else if(num[1]==mins) printf("%s %s\n",laa[0],laa[1]);
    else if(num[2]==mins) printf("%s %s\n",smb[0],smb[1]);
    else if(num[3]==mins) printf("%s %s\n",lab[0],lab[1]);
  }else{
    minflg=false;
    if(num[0]==mins){
      mintmp[0]=strtoull(sma[0],NULL,10);
	mintmp[1]=strtoull(sma[1],NULL,10);
	minflg=true;
	mval=0;
    }
    if(num[1]==mins){
      if(!minflg){
	mintmp[0]=strtoull(laa[0],NULL,10);
	mintmp[1]=strtoull(laa[1],NULL,10);
	minflg=true;
	mval=1;
      }else{
	tmp[0]=strtoull(laa[0],NULL,10);
	if(tmp[0]<=mintmp[0]){
	  tmp[1]=strtoull(laa[1],NULL,10);
	  if((mintmp[0]==tmp[0] && tmp[1]<=mintmp[1]) || mintmp[0]>tmp[0]){
	    mintmp[0]=tmp[0];
	    mintmp[1]=tmp[1];
	    mval=1;
	  }
	}
      }
    }
    if(num[2]==mins){
      if(!minflg){
	mintmp[0]=strtoull(smb[0],NULL,10);
	mintmp[1]=strtoull(smb[1],NULL,10);
	minflg=true;
	mval=2;
      }else{
	tmp[0]=strtoull(smb[0],NULL,10);
	if(tmp[0]<=mintmp[0]){
	  tmp[1]=strtoull(smb[1],NULL,10);
	  if((mintmp[0]==tmp[0] && tmp[1]<=mintmp[1]) || mintmp[0]>tmp[0]){
	    mintmp[0]=tmp[0];
	    mintmp[1]=tmp[1];
	    mval=2;
	  }
	}
      }
    }
    if(num[3]==mins){
      if(!minflg){
	mintmp[0]=strtoull(lab[0],NULL,10);
	mintmp[1]=strtoull(lab[1],NULL,10);
	minflg=true;
	mval=3;
      }else{
	tmp[0]=strtoull(lab[0],NULL,10);
	if(tmp[0]<=mintmp[0]){
	  tmp[1]=strtoull(lab[1],NULL,10);
	  if((mintmp[0]==tmp[0] && tmp[1]<=mintmp[1]) || mintmp[0]>tmp[0]){
	    mintmp[0]=tmp[0];
	    mintmp[1]=tmp[1];
	    mval=3;
	  }
	}
      }
    }
    
    switch(mval){
    case 0:
      printf("%s %s\n",sma[0],sma[1]);
      break;
    case 1:
      printf("%s %s\n",laa[0],laa[1]);
      break;
    case 2:
      printf("%s %s\n",smb[0],smb[1]);
      break;
    case 3:
      printf("%s %s\n",lab[0],lab[1]);
      break;
    }

  }
}
