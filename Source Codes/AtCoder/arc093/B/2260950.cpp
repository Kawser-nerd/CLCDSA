#include <cstdio>
using namespace std;

int main(){
    int A, B;
//    int landscape;
    bool fl = true;
    int dotVBlocks, sharpVBlocks;

    scanf("%d%d",&A, &B);

    dotVBlocks = (A-1) / 50;
    sharpVBlocks = (B-1) / 50;

    printf("%d %d\n",dotVBlocks*2+sharpVBlocks*2+4,100);

    for(int i = 0; i < dotVBlocks; i++){
        fl = true;
        for(int j = 0; j < 100; j++){
            if(fl) printf("#");
            else printf(".");
            fl = !fl;
        }
        printf("\n");
        for(int j = 0; j < 100; j++){
            printf("#");
        }
        printf("\n");
    }

    fl = true;
    for(int j = 0; j < 100; j++){
        if(fl) printf("#");
        else if(j <= ((A-1)%50)*2) printf(".");
        else printf("#");
        fl = !fl;
    }
    printf("\n");


    for(int j = 0; j < 100; j++){
        printf("#");
    }
    printf("\n");

    for(int j = 0; j < 100; j++){
        printf(".");
    }
    printf("\n");


    fl = true;
    for(int j = 0; j < 100; j++){
        if(fl) printf(".");
        else if(j <= ((B-1)%50)*2) printf("#");
        else printf(".");
        fl = !fl;
    }
    printf("\n");


    for(int i = 0; i < sharpVBlocks; i++){
        for(int j = 0; j < 100; j++){
            printf(".");
        }
        printf("\n");
        fl = true;
        for(int j = 0; j < 100; j++){
            if(fl) printf("#");
            else printf(".");
            fl = !fl;
        }
        printf("\n");
    }


/*
    landscape = (A+B)*2-2;

    printf("2 %d\n",landscape);

    for(int i = 0; i < landscape; i++){
        if(i <= A*2-2) printf("#");
        else printf(".");
    }

    printf("\n");

    for(int i = 0; i < landscape; i++){
        if(fl) printf("#");
        else printf(".");
        fl = !fl;
    }
    printf("\n");
*/
    return 0;
}