N, M, C = map(int, input().split())
B = list(map(int, input().split()))
As = [list(map(int, input().split())) for _ in range(N)]

ans = 0

for A in As:
  score = 0
  for i in range(M):
    score += A[i]*B[i]
  if score + C > 0:
    ans += 1

print(ans)