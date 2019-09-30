N, K = map(int, input().split())
R = list(map(int, input().split()))

R = sorted(R)
R = R[-K:]

ans = 0
for r in R:
    ans = (ans + r)/2

print(ans)