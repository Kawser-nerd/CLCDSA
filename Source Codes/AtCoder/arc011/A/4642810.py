m,n,d = map(int,input().split())
ans = d
while d >= m:
    ans += d // m * n
    d = n*(d // m) + d % m
print(ans)