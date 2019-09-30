#include <iostream>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
typedef tuple<int,int,int,int> Tile;
map<Tile,int> M;
vector<Tile> V;

int self_dub(Tile t){
    int i=1;
    if(t==Tile(get<1>(t),get<2>(t),get<3>(t),get<0>(t)))i++;
    if(t==Tile(get<2>(t),get<3>(t),get<0>(t),get<1>(t)))i++;
    if(t==Tile(get<3>(t),get<0>(t),get<1>(t),get<2>(t)))i++;
    return i;
}

bool equal(Tile a, Tile b){
    int A[4],B[4];
    A[0]=get<0>(a);A[1]=get<1>(a);A[2]=get<2>(a);A[3]=get<3>(a);
    B[0]=get<0>(b);B[1]=get<1>(b);B[2]=get<2>(b);B[3]=get<3>(b);
    if(A[0]==B[0]&&A[1]==B[1]&&A[2]==B[2]&&A[3]==B[3]) return true;
    if(A[0]==B[1]&&A[1]==B[2]&&A[2]==B[3]&&A[3]==B[0]) return true;
    if(A[0]==B[2]&&A[1]==B[3]&&A[2]==B[0]&&A[3]==B[1]) return true;
    if(A[0]==B[3]&&A[1]==B[0]&&A[2]==B[1]&&A[3]==B[2]) return true;
    return false;
}

int64_t cnt(int i, int j, int d){
    Tile T[6];
    T[0]=V[i];
    int Bo[4];
    Bo[(0+d)%4]=get<0>(V[j]);
    Bo[(1+d)%4]=get<1>(V[j]);
    Bo[(2+d)%4]=get<2>(V[j]);
    Bo[(3+d)%4]=get<3>(V[j]);    
    T[1]=Tile(Bo[0],Bo[1],Bo[2],Bo[3]);
    T[2]=Tile(get<1>(T[0]),get<0>(T[0]),get<1>(T[1]),get<0>(T[1]));
    T[3]=Tile(get<2>(T[0]),get<1>(T[0]),get<0>(T[1]),get<3>(T[1]));
    T[4]=Tile(get<3>(T[0]),get<2>(T[0]),get<3>(T[1]),get<2>(T[1]));
    T[5]=Tile(get<0>(T[0]),get<3>(T[0]),get<2>(T[1]),get<1>(T[1]));
    int Dub[6]={};
    for(int a=0;a<6;a++){
        for(int b=a+1;b<6;b++){
            if(equal(T[a],T[b])){
                Dub[b]+=self_dub(T[b]);
            }
        }
    }
    int64_t ret=1;
    for(int i=2;i<6;i++){
        int64_t p=0;
        if(M.find(T[i])!=M.end()){
            p=M[T[i]]-Dub[i];
        }
        ret*=p;
    }
    return ret;
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int c0,c1,c2,c3;
        cin>>c0>>c1>>c2>>c3;
        V.emplace_back(c0,c1,c2,c3);
        M[Tile(c0,c1,c2,c3)]++;
        M[Tile(c1,c2,c3,c0)]++;
        M[Tile(c2,c3,c0,c1)]++;
        M[Tile(c3,c0,c1,c2)]++;
    }
    int64_t ans=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int d=0;d<4;d++){
                ans+=cnt(i,j,d);
                // if(cnt(i,j,d))cout<<i<<' '<<j<<' '<<d<<' '<<cnt(i,j,d)<<endl;
            }
        }
    }
    cout<<ans/3<<endl;
    return 0;
}