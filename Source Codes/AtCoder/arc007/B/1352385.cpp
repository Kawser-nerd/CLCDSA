#include <iostream>
using namespace std;

int main(){
    int N, M;
    int head = 0;
    cin >> N >> M;

    int nums[N+1];
    for(int i = 1; i <= N; ++i){
        nums[i] = i;
    }
    for(int i = 0; i < M; ++i){
        int input;
        cin >> input;
        
        int index; 
        int flag = 0;
        for(int j = 1; j <= N; ++j){
            if(input == nums[j]){
                index = j;
                flag = 1;
                break;
            }
        }
        if(flag){
            int temp = head;
            head = nums[index];
            nums[index] = temp;
        }
    }

    for(int i = 1; i <= N; ++i){
        cout << nums[i] << endl;
    }

    return 0;
}