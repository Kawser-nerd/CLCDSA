#include <stdio.h>

int table[30][2][505]={0};
char str[505]={0},x;
int N,i,j,k,sum,sizeM;

void reset(){
    int i,j,k,size;
    for(i=0;i<30;i++){
        size=table[i][0][0];
        for(j=0;j<2;j++){
            for(k=0;k<=size;k++){
                table[i][j][k]=0;    
            }    
        }    
    }    
}

void add(char a, char b){
    int sizeA,sizeB,i,j,count; 
    if(a==' '){
        a=29;    
    }else{
        a-='a';    
    }
    if(b==' '){
        b=29;    
    }else{
        b-='a';    
    }
    sizeA=table[a][0][0],sizeB=table[b][0][0]; 
    for(i=1;i<=sizeB;i++){
        count=0;
        for(j=1;j<=sizeA;j++){
            if(table[b][0][i]>table[a][0][j]){
                count+=table[a][1][j];    
            }
        }   
        if(count>=10000){
            count%=10000;    
        }
        table[b][1][i]=count;
    }
}

int main(){
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d\n",&N);
    for(k=1;k<=N;k++){
        reset();
        gets(str);
        for(i=0;str[i]!='\0';i++){
            x=str[i];
            if(x==' '){
                table[29][0][++table[29][0][0]]=i;    
            }else{
                table[x-'a'][0][++table[x-'a'][0][0]]=i;
            }
        }
        j='w'-'a';
        sizeM=table[j][0][0];
        for(i=1;i<=sizeM;i++){
            table[j][1][i]=1; 
        }
        add('w','e');
        add('e','l');
        add('l','c');
        add('c','o');
        add('o','m');
        add('m','e');
        add('e',' ');
        add(' ','t');
        add('t','o');
        add('o',' ');
        add(' ','c');
        add('c','o');
        add('o','d');
        add('d','e');
        add('e',' ');
        add(' ','j');
        add('j','a');
        add('a','m');
        j='m'-'a';
        sizeM=table[j][0][0];
        sum=0;
        for(i=1;i<=sizeM;i++){
            sum+=table[j][1][i];  
        }
        if(sum>=10000){
            sum%=10000;    
        }
        printf("Case #%d: ",k);
        if(sum<10){
            printf("000");    
        }else if(sum<100){
            printf("00"); 
        }else if(sum<1000){
            printf("0"); 
        }
        printf("%d\n",sum);
    }
    scanf(" ");
    return 0;
}
