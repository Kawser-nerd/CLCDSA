c = int(input())
t = []
n, m, l = 0, 0, 0
for i in range(c):
  temp = list(map(int, input().split()))
  t.append(sorted(temp))

for i in t:
  n = max(n, i[0])
  m = max(m, i[1])
  l = max(l, i[2])

print(n * m * l)