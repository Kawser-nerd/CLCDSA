import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n=int(input())
Edges=[[] for _ in range(n)]
for i in range(n-1):
    a,b=map(int,input().split())
    a-=1
    b-=1
    Edges[a].append(b)
    Edges[b].append(a)
while sum([len(Edges[i]) for i in range(n)]):
    for i in range(n):
        if len(Edges[i])==1:
            j=Edges[i][0]
            Edges[i].remove(j)
            Edges[j].remove(i)
            for k in Edges[j]:
                Edges[k].remove(j)
                if not Edges[k]:
                    print('First')
                    exit()
            Edges[j]=[]
print('Second')