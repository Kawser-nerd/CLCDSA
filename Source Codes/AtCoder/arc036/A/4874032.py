N, K = map(int, input().split())
T = [int(input()) for i in range(N)]

ans = sum(T[:2]) 
for i in range(2, N):
    ans += T[i]
    if ans < K:
        print(i + 1)
        break
    ans -= T[i - 2]
else:
    print(-1)