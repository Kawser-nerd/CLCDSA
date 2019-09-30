#include <cstring>
#include <map>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[100010];

int main()
{

//    freopen("D:\\Code\\TestData\\data_in.txt","r",stdin);
//    freopen("D:\\Code\\TestData\\data_in.txt","w",stdout);
//    printf("100000\n");
//    for(int i=1;i<=100000;i++){
//        printf("%d ",i);
//    }
//    printf("\n");
    int loop;

    while(~scanf("%d", &loop))
    {
        for(int i=1;i<=loop;i++){
            scanf("%d",&arr[i]);
        }

        bool f=false;
        int pre=0;
        int res=0;
        for(int i=1;i<=loop;i++){
            if(arr[i]==i){
                if(f){
                   if(i-pre==1){
                        f=false;
                   }else{
                        res++;
                        f=false;
                   }
                }else{
                    pre=i;
                    f=true;
                    res++;
                }
            }else{
                f=false;
            }
        }
        printf("%d\n",res);

    }
    return 0;
}