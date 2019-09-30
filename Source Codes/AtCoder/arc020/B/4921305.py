n,c=map(int,input().split())
a=[int(input())for i in range(n)]
d=n
for i in range(1,11):
    for j in range(1,11):
        if i!=j:
            e=0
            h=[i,j]*(n//2+1)
            for s in range(n):
                if h[s]!=a[s]:
                    e+=1
            else:
                d=min(e,d)
print(d*c)