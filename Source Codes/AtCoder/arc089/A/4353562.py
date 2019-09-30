N=int(input())
t=list()
t=[(0,(0,0))]
for i in range(N):
        T,a,b=map(int,input().split())
        t.append((T,(a,b)))

ans="Yes"
for i in range(N):
        n=abs(t[i][1][0]-t[i+1][1][0])+abs(t[i][1][1]-t[i+1][1][1])
        if(n%2!=(t[i+1][0]-t[i][0])%2 or n>(t[i+1][0]-t[i][0])):
                ans="No"

print(ans)