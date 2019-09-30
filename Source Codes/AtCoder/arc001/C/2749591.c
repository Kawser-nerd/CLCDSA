#include <stdio.h>
#include <string.h>

int x[8],y[8],s[15],t[15];
char z[8][8];
char *zz[8];
int p,u,r,end,set;
void queen(void);
void reset(void);
void check(void);

void queen(void){
    int k;
    int skip=0;

    if(x[r]<3){
        skip=1;
    }

    if(skip==0){
        set=0;
    for(;u<8;u++){
        if(x[r]>=p &&
            y[u]>=p &&
            s[r+u+1]>=p &&
            t[r-u+7]>=p ){
                x[r]=p;
                y[u]=p;   
                s[r+u+1]=p;
                t[r-u+7]=p;
                set = 1;
                break;
            }
        }

    if(set==0){
        r--;
        p--;
        reset();
    }if(set==1){
        r++;
        p++;
        u=0;
    }
    }else{//skip==1
        if(set==0){
        r--;
        reset();
    }if(set==1){
        r++;
        u=0;
    }
    }

    if(r==-1){
        end = 1;
        return;
        }
    if(r==8){
        end = 0;
        return;
        }
    queen();
}


void reset(void){
    int k;
    if(x[r]>2){ 
          for (k=0; k<8;k++){
          if(y[k]==p){
            //initialize
            x[r]=8;
            y[k]=8;   
            s[r+k+1]=8;
            t[r-k+7]=8;
            //initial u
            u=k+1;
            break;
          }
          }
    }else{
        r--;
        reset();
    }
}

void check(){
    int i, j,n;
     n = 0;

  for (i=0; i<8; i++){
    for (j=0; j<8; j++){
        if(strncmp("Q",&zz[i][j],1)==0){
        if(x[j] != 8 ||
            y[i] != 8 ||
            s[j+i+1] != 8 ||
            t[j-i+7] != 8){
            end = 1;
            j=8,i=8;
        }else{
            x[j]=n;
            y[i]=n;   
            s[j+i+1]=n;
            t[j-i+7]=n;           
            n++;
            }
        }
    }
}
}


int main(void){
    int i,j,k;
    char input[9];
    for(i=0;i<8;i++)
    {x[i]=8;
    y[i]=8;}
    for(i=0;i<15;i++)
    {s[i]=8;
    t[i]=8;}

     p=3;
     u=0;
     r=0;
     end=0;
     set=1;


   for(i=0;i<8;i++){
        gets(input);
        for(j=0;j<8;j++){
         z[i][j]=input[j];
        }
    }

    for (j=0;j<8;j++) zz[j] = z[j];

    for(int a=0;a<1;a++){
    check();
    if(end==1){
        break;
    }

    queen();
    if(end==1){
        break;
    }

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(x[i]==y[j]){
                z[j][i]='Q';
            }
        }
    }

    for(j=0;j<8;j++){
        for(i=0;i<8;i++){
         printf("%c",z[j][i]);
        }
               printf("\n");
      }
      
    }

    if(end==1){
        printf("No Answer");
    }

return 0;
} ./Main.c: In function ‘main’:
./Main.c:132:9: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
         gets(input);
         ^
/tmp/ccN7l859.o: In function `main':
Main.c:(.text.startup+0x9e): warning: the `gets' function is dangerous and should not be used.