n,h = map(int,input().split())
a,b,c,d,e = map(int,input().split())
ans = 10**20
for i in range(n+1):
    j = max(0,(-h-b*i+e*(n-i))//(d+e) +1)
    ans = min(ans,a*i+c*j)           
print(ans)