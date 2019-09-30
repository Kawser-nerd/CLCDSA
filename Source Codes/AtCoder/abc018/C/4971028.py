from itertools import accumulate as ac
r,c,k=map(int,input().split())
d=[[0]*(c+1) for i in range(r)]
for i in range(r):
    g=input()
    for j in range(c):
        if g[j]=="x":
            for t in range(k):
                if i-k>=0:
                    d[i-t][max(0,j-k+t+1)]+=1
                    d[i-t][min(c,j+k-t)]-=1
                if i+k<r:
                    d[i+t][max(0,j-k+t+1)]+=1
                    d[i+t][min(c,j+k-t)]-=1
d=[list(ac(i))for i in d]
t=0
for x in range(k-1,r-k+1):
    for y in range(k-1,c-k+1):
        if d[x][y]==0:
            t+=1
print(t)