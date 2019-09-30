#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    int N,M;
    set<int> A;
    map<int,int> B;
    cin>>N>>M;
    for (int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        if (A.find(a) != A.end()){
            B[a]+=b;
        }
        else{
            B[a]=b;
        }
        A.insert(a);
    }
    vector<int> Avec(A.begin(),A.end());
    sort(Avec.begin(),Avec.end());
    int num=A.size();
    int long number=0;
    int long price=0;
    for (int i=0;i<num;i++){
        if (B[Avec[i]]+number>=M){
            price+=(M-number)*Avec[i];
            cout<<price<<endl;
            break;
        }
        else{
            price+=Avec[i]*B[Avec[i]];
            number+=B[Avec[i]];
        }
    }
    
}