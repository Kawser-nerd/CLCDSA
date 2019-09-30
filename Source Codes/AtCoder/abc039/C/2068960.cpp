#include <iostream>
using namespace std;

int mod(int i,int j) {
    return (i % j) < 0 ? (i % j) + 0 + (j < 0 ? -j : j) : (i % j + 0);
}

int main(void){
    char str[12][4] = {"Do","Do","Re","Re","Mi","Fa","Fa", "So", "So", "La","La", "Si"};
    char patt[36][2] = {"W","B","W","B","W","W","B","W","B","W","B","W","W","B","W","B","W","W","B","W","B","W","B","W","W","B","W","B","W","W","B","W","B","W","B","W"};
    char inp[20][2];
    
    for(int i = 0 ; i < 20; i++){
        scanf("%c", &inp[i][0]);
        inp[i][1] = '\0';
    }
    
    int count = 0;
    int point = 0;
    while(count < 20 && point < 36){
        //printf("%s == %s,%d,%d\n",patt[point+count],inp[count],inp[count][0]==patt[point+count][0],count);
        if(patt[point+count][0] == inp[count][0]){
            count++;
        }else{
            point++;
            count = 0;
        }
    }
    printf("%s",str[mod((point),12)]);
}