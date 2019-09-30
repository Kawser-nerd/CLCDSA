#include<ios>
int main(){
    //char sS[7] = {'1','2','3','4','5','6','\0'};
    char sS[] = "123456";
    int iN;
    scanf("%d",&iN);
    iN %= 30;
    for(int i=0;i<iN;i++){
        std::swap(sS[i%5],sS[i%5+1]);
    }
    printf("%s\n",sS);
    return 0;
}