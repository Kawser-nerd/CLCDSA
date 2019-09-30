from itertools import*
n,q=map(int,input().split())
x=[0 for i in range(n)]
for i in range(q):
    a,b=map(int,input().split())
    x[a-1]+=1
    if b!=n:
        x[b]-=1
print("".join(map(str,[i%2 for i in accumulate(x)])))