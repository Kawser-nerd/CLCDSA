//
//  main.c
//  A_DominoPaint
//
//  Created by T.T on 2016/05/14.
//  Copyright © 2016? T.T. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    long a,b,dist;
} magic;

//??????
void swapMagic(magic *magic1, magic *magic2){
    magic cache;
    
    cache = *magic1;
    *magic1 = *magic2;
    *magic2 = cache;
}

//magic?dist???????
int compare_magic_dist(const void *c, const void*d){
    magic magicA = *(magic*)c;
    magic magicB = *(magic*)d;
    
    if((magicA.dist-magicB.dist)>0) return 1;
    else if((magicA.dist-magicB.dist)==0) return 0;
    else return -1;
}

//magic?a???????
int compare_magic_a(const void *c, const void*d){
    magic magicA = *(magic*)c;
    magic magicB = *(magic*)d;
    
    if((magicA.a-magicB.a)>0) return 1;
    else if((magicA.a-magicB.a)==0) return 0;
    else return -1;
    
    
}
//magic?b???????
int compare_magic_b(const void *c, const void*d){
    magic magicA = *(magic*)c;
    magic magicB = *(magic*)d;
    
    if((magicA.b-magicB.b)>0) return -1;
    else if((magicA.b-magicB.b)==0) return 0;
    else return 1;
    
    
}


//magic???????
int compare_magic(const void *c, const void*d){
    magic magicA = *(magic*)c;
    magic magicB = *(magic*)d;
    
    //??magicA.dist?magicB.dist??????????
    if(magicA.dist>0 && magicB.dist>0){
        //b?????????????????
        if((magicA.b-magicB.b)>0) return -1;
        else if((magicA.b-magicB.b)==0) return 0;
        else return 1;
    }
    else{
        
        if((magicA.dist-magicB.dist)>0) return 1;
        //??dist???????????
        else if((magicA.dist-magicB.dist)==0) {
            //a??????
            if((magicA.a-magicB.a)>0) return 1;
            else if((magicA.a-magicB.a)==0) return 0;
            else return -1;
            
        }
        else return -1;
    }
}

int main(int argc, const char * argv[]) {
    
    
    long N;
    long int i;
    
    long int max=0;
    long int currentTmp=0;
    
    long int minus=0;
    long int plus=0;
    long int zero=0;
    
    //N?????
    scanf("%ld",&N);
    
    magic *magics =(magic*)malloc(sizeof(magic)*(N+1));
    
    for(i=0;i<N;i++){
        //??????
        scanf("%ld %ld",&magics[i].a,&magics[i].b);
        //??????????????
        magics[i].dist=magics[i].a - magics[i].b;
    }
    
    
    //?????dist??????????
    qsort(magics, (size_t)N, sizeof(magic), compare_magic_dist);
    
    //dist?0????????????
    for(i=0;i<N;i++){
        if(magics[i].dist<0){
            minus++;
        }
        else if(magics[i].dist ==0){
            zero++;
        }
        else{
            plus++;
        }
    }
    
#ifdef DEBUG

        printf("minus=%ld zero=%ld plus=%ld\n",minus,zero,plus);
    
#endif
    
    //minus??a?????
    qsort(magics, (size_t)(minus), sizeof(magic), compare_magic_a);
    //zero?????????
    //plus??b???????????
    qsort(&magics[minus+zero], plus, sizeof(magic), compare_magic_b);

    
    
    
#ifdef DEBUG
    for(i=0;i<N;i++){
        printf("%ld: (%ld %ld %ld)\n",i,magics[i].a ,magics[i].b,magics[i].dist);
    }
#endif
    
    for(i=0;i<N;i++){
        max = fmaxl(max, currentTmp+ magics[i].a);
        currentTmp += magics[i].dist;
    }
    
    printf("%ld\n",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:101:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&N);
     ^
./Main.c:107:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld %ld",&magics[i].a,&magics[i].b);
         ^