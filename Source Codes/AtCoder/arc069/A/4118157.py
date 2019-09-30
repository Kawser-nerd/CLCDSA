N, M = map(int, input().split())

ans = 0
if N == M//2:
    ans = N
elif N > M//2:
    ans = M//2
else:
    diff = M-2*N
    ans = N
    ans += diff//4
print(ans)