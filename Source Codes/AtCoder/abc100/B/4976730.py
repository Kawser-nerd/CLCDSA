D, N = map(int, input().split())

ans = N*100**D
if N == 100:
    ans += 1*100**D
print(ans)