n = int(input())
l = [0 for _ in range(6)]
for _ in range(n):
  a, b = map(float, input().split())
  if a >= 35:
    l[0] += 1
  elif a >= 30:
    l[1] += 1
  elif a >= 25:
    l[2] += 1
  if b >= 25:
    l[3] += 1
  if b < 0 <= a:
    l[4] += 1
  if a < 0:
    l[5] += 1
print(" ".join(list(map(str, l))))