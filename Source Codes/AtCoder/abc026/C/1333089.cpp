#include <iostream>
#include <stdlib.h>
using namespace std;

/*int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int max(int length, int nums[]){
    int m = nums[0];
    for(int i = 0; i < length; ++i){
        if(m < nums[i]){
            m = nums[i];
        }
    }
    return ans;
}

int min(int length, int nums[]){
    int m = nums[0];
    for(int i = 0; i < length; ++i){
        if(m > nums[i] && ){
            m = nums[i];
        }
    }
    return ans;
}
*/
int maxG(int p, int length, int nums[], int total[]){
    int m = 0;
    int flag = 0;
    for(int i = 1; i < length; ++i){
        if(m < total[i+1] && p == nums[i]){
            m = total[i+1];
            flag = 1;
        }
    }
    if(!flag)m = 0;
    return m;
}

int minG(int p, int length, int nums[], int total[]){
    int m = 10000000;
    int flag = 0;
    for(int i = 1; i < length; ++i){
        if(m > total[i+1] && p == nums[i]){
            m = total[i+1];
            flag = 1;
        }
    }
    if(!flag)m = 0;
    return m;
}

/*int makeSum(int length, int nums[]){
    int 
}*/

int main(){
    int N, tempMax, tempMin;
    cin >> N;
    int nums[N];
    int total[N+1];
    total[N] = 1;
    for(int i = 1; i < N; ++i){ 
        cin >> nums[i]; 
        total[i] = 1;
    }
    
    for(int i = N-1; i > 0; --i){
        tempMin = minG(i,N,nums,total);
        tempMax = maxG(i,N,nums,total);
        
        //cout << "i = " << i << ", tempMin, tempMax = " << tempMin << ", " << tempMax << endl;
        total[i] += tempMin + tempMax;
    }

    //for(int i = 1;i < N; ++i)cout << total[i] << endl;
        
    cout << total[1] << endl;
    return 0;
}