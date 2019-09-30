N,A,B,C,D = map(int,input().split())
ans = "NO"
for k in range(N-1):
    if k*C - (N-1-k)*D <= B-A <= k*D - (N-1-k)*C:
        ans = "YES"
        break
print(ans)