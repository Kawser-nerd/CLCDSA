#include<cstdio>

int abs(int x){
    return x>0?x:-x;
}

int main(){
    int A,B;
    scanf("%d%d",&A,&B);
    if(A<=B){
        if((A<0&&B<=0)||(A>=0))
            printf("%d",B-A);
        else//-10 11
            printf("%d",abs(abs(A)-abs(B))+1);
    }
    else{
        if((A<0)||(A>0&&B>0))//-10 -20 20 10
            printf("%d",A-B+2);
        else//10 -20  20 -10
            printf("%d",abs(abs(B)-abs(A))+1);
    }
}