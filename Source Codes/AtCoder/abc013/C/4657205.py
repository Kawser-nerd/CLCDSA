n,h = map(int,input().split())
a,b,c,d,e = map(int,input().split())
ans = float("inf")
for i in range(n+1):
    j = max(0,((n-i)*e-h-b*i)//(d+e)+1)
    ans = min(ans,a*i+c*j)
print(ans)