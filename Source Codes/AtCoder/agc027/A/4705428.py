N,X = map(int,input().split())
A = list(map(int,input().split()))
A.sort()

ans = 0
for a in A:
    if X-a < 0: break
    X -= a
    ans += 1
else:
    if X:
        ans -= 1
print(ans)