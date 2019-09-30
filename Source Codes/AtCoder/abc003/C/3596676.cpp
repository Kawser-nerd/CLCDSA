#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
vector<int> bubbleSort(vector<int> v){
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]>v[j]){
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    return v;
}

void printVector(vector<int> v){
    for(auto itr = v.begin(); itr != v.end(); ++itr){
        cout << *itr << " ";
    }
}

int main(void){
    // Your code here!
    int N, K;
    int in;
    vector<int> rates;
    
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> in;
        rates.push_back(in);
    }
    
    rates = bubbleSort(rates);
    
    double score = 0;
    for(auto itr = rates.begin() + (N-K); itr != rates.end(); ++itr){
        score = (score + *itr) / 2.0;
    }
    cout << fixed << setprecision(7) << score << endl;
}