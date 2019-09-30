N, A, B = map(int, input().split())

ans = list(range(A))
m = 0
rest = N - A
B -= 1
if rest < B:
  print(-1)
  exit()
if rest / A > B:
  print(-1)
  exit()

while rest > B:
  s = min(A, rest - B + 1)
  ans += list(range(m - s, m))
  m -= s
  rest -= s
  B -= 1

ans += list(range(m - B, m))[::-1]
m -= B

print(" ".join([str(x - m + 1) for x in ans]))