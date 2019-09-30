import sys,collections,itertools

def solve():
    N,K = map(int,input().split())
    A = list(map(int,input().split()))
    NNMSum = [0 for i in range(N)]
    NNSum = [0 for i in range(N)]
    NNMSum[0] = min(0,A[0])
    NNSum[0] = max(0,A[0])
    for i in range(N-1):
        NNSum[i+1] = NNSum[i] + max(0,A[i+1])
        NNMSum[i+1] = NNMSum[i] + min(0,A[i+1])
    ans = max(NNSum[N-1] - NNSum[K-1], NNSum[N-1] + NNMSum[K-1])
    #print(0,NNSum[N-1] - NNSum[K-1], NNSum[N-1] + NNMSum[K-1])
    for i in range(1,N-K+1):
        ans = max(ans,NNSum[N-1] - (NNSum[i+K-1] - NNSum[i-1]),NNSum[N-1] - (NNMSum[i-1] - NNMSum[i+K-1]))
        #print(i,NNSum[N-1] - (NNSum[i+K-1] - NNSum[i-1]),NNSum[N-1] - (NNMSum[i-1] - NNMSum[i+K-1]))
    print(ans)    
        
solve()