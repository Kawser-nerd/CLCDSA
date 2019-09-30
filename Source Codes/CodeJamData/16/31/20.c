#include <stdio.h>

int main(void){
    int cases, casos, i, j;
    int partidos, maximo, total;
    int parties[30];

    scanf("%d\n",&cases);
    for(casos=1;casos<=cases;casos++){
        scanf("%d\n",&partidos);
        total = maximo = 0;
        for(i=0;i<partidos;i++){
            scanf("%d",&parties[i]);
            total += parties[i];
            if(parties[i] > maximo){
                maximo = parties[i];
            }
        }
        //printf(" %d\n",total);

        printf("Case #%d: ",casos);

        while(total){
            for(i=0;i<partidos;i++){
                if(parties[i] == maximo){
                    if((total % 2) == 0){
                        printf("%c",'A'+i);
                    }else{
                        printf("%c ",'A'+i);
                    }
                    total--;
                    parties[i]--;
                }
            }
            maximo--;
        }
        printf("\n");
    }

    return(0);
}
