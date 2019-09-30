N = int(input())

ans = 0
for _ in range(N):
    scores = [int(i) for i in input().split()]
    ans = max(ans, sum(scores[:-1]) + scores[-1] * 110 / 900)

print(ans)