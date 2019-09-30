n, m = map(int, input().split())
red = [False for _ in range(n)]
nb = [1 for _ in range(n)]
red[0] = True
for _ in range(m):
  x, y = map(int, input().split())
  if red[x-1]:
    red[y-1] = True
  nb[x-1] -= 1
  nb[y-1] += 1
  if nb[x-1] == 0:
    red[x-1] = False

print(sum(1 for r in red if r))