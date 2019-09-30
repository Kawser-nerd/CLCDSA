#include <iostream>
#include <utility>
using namespace std;
void operation(int *arr, int N){
    for(int i=0;i<N;i++){
        swap(arr[i%5],arr[(i%5)+1]);
    }
}
int main(void){
    // Your code here!
    int arr[] = {1,2,3,4,5,6};
    int N;
    
    cin >> N;
    
    operation(arr, N%30);
    
    for(auto x :arr){
        cout << x;
    }
}