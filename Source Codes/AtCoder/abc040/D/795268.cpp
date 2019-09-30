#include <algorithm>
#include <cstdio>
#include <numeric>
#include <utility>
#define D(X) X[200000],
#define L(S,M,Y) iota(S,S+M,0);sort(S,S+M,[&](int i,int j){return Y[i]>Y[j];});
using namespace std;int D(A)D(B)D(Y)D(V)D(W)D(O)D(S)D(T)D(P)D(C)N,M,Q,R,I,J,K,Z;int F(int X){return P[X]-X?P[X]=F(P[X]):X;}int main(){scanf("%d%d",&N,&M);for(;I<M;++I)scanf("%d%d%d",A+I,B+I,Y+I);scanf("%d",&Q);for(I=0;I<Q;++I)scanf("%d%d",V+I,W+I);L(S,M,Y);L(T,Q,W);iota(P,P+N,0);fill(C,C+N,1);for(I=0;I<Q;O[Z]=C[F(V[Z]-1)],++I)for(Z=T[I];R<M&&W[Z]<Y[S[R]];J=F(A[S[R]]-1),K=F(B[S[R++]]-1),J-K?P[J]=K,C[K]+=C[J]:0);for(I=0;I<Q;)printf("%d\n",O[I++]);}