N, T = map(int, input().split())
times = [int(input()) for i in range(N)]
ans = N * T
for i in range(N-1):
    if times[i+1] - times[i] < T:
        ans -= T - (times[i+1] - times[i])
print(ans)