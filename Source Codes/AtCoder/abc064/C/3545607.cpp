// ABC 064 C
#include <iostream>
#include <numeric>

using namespace std;

int arraySum(int a[], int n)
{
    int initial_sum  = 0;
    return accumulate(a, a+n, initial_sum);
}


int main(){

    // N : # of players
    // a_1, ...., a_N : ratings of players
    
    int N;
    scanf("%d", &N);
    //int ratings[N+1];
    int ans = 0;
    int divisions[8] = {0};
    int above_red = 0;
    int rating;
    
    
    for(int i=0; i<N; i++){
        scanf("%d", &rating);
        //ratings[i] = rating;
        
        if(rating >=1 && rating <= 399){
            divisions[0] = 1;
        } else if(rating >=400 && rating <= 799){
            divisions[1] = 1;
        } else if(rating >=800 && rating <= 1199){
            divisions[2] = 1;
        } else if(rating >=1200 && rating <= 1599){
            divisions[3] = 1;
        } else if(rating >=1600 && rating <= 1999){
            divisions[4] = 1;
        } else if(rating >=2000 && rating <= 2399){
            divisions[5] = 1;
        } else if(rating >=2400 && rating <= 2799){
            divisions[6] = 1;
        } else if(rating >=2800 && rating <= 3199){
            divisions[7] = 1;
        } else if(rating >=3200){
            above_red += 1;
        }
    }
    
    bool all_above_red = true;
    for(int i=0; i<8; i++){
        if(divisions[i]){
            all_above_red = false;
            break;
        }
    }
    
    if(all_above_red){
        cout << 1 << " " << above_red << endl;
        return 0;
    } else {
        cout << arraySum(divisions, sizeof(divisions)/sizeof(divisions[0])) << " " << arraySum(divisions, sizeof(divisions)/sizeof(divisions[0]))+above_red << endl;
    }
    
    return 0;
}