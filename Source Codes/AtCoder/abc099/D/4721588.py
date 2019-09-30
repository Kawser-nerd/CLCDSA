from collections import defaultdict
n,c=map(int,input().split())
x=[list(map(int,input().split()))for i in range(c)]
e=[[0]*c for i in range(3)]
for i in range(n):
    a=list(map(int,input().split()))
    for j in range(n):
        e[(i+j+2)%3][a[j]-1]+=1
p=float("inf")
for i in range(c):
    for j in range(c):
            if i!=j:
                for h in range(c):
                    if i!=h and j!=h:
                        p=min(p,sum([x[s][i]*d for s,d in enumerate(e[0])]+[x[s][j]*d for s,d in enumerate(e[1])]+[x[s][h]*d for s,d in enumerate(e[2])]))
print(p)