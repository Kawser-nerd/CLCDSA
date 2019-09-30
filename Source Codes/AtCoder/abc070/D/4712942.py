from collections import deque
class edge:
    def __init__(self,to,cost):
        self.to=to
        self.cost=cost

N=int(input())
G=[list() for i in range(N)]
P=[False for i in range(N)]
A=[-100 for i in range(N)]
for i in range(N-1):
    a,b,c=map(int,input().split())
    G[a-1].append(edge(b-1,c))
    G[b-1].append(edge(a-1,c)) #??????????



def solve(G,K,P):
    q=deque()
    q.append(K)
    while q:
        s=q.pop()
        for i in G[s]:
            if(P[i.to]):
                continue
            P[i.to]=True
            A[i.to]=A[s]+i.cost
            q.append(i.to)

Q,K=map(int,input().split())
A[K-1]=0
P[K-1]=True
solve(G,K-1,P)


for i in range(Q):
    x,y=map(int,input().split())
    
    print(A[x-1]+A[y-1])