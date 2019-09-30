#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(void){
    int N,K,Q;
    scanf("%d %d %d",&N,&K,&Q);
    vector<int> A;
    A.resize(N);
    for(int i=0;i<N;i++)scanf("%d",&A[i]);
    vector<int> B;
    B=A;
    sort(B.begin(),B.end());
    int ans=1145141919;
    for(int i=0;i<N;i++){
        priority_queue<int,vector<int> , greater<int> > po;
        vector<int> buri;
        priority_queue<int,vector<int> , greater<int> > emp;
        for(int j=0;j<N;j++){
            if(A[j]<B[i]){
                while(po.size()>=K){buri.push_back(po.top());po.pop();}
                po=emp;
            }
            else po.push(A[j]);
            if(j==N-1){
                while(po.size()>=K){buri.push_back(po.top());po.pop();}
                po=emp;
            }
        }
        sort(buri.begin(),buri.end());
        if(buri.size()>=Q&&ans>buri[Q-1]-buri[0])ans=buri[Q-1]-buri[0];
    }
    printf("%d",ans);
    return 0;
}