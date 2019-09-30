d = list(map(int, input().split()))
j = list(map(int, input().split()))
s = 0
for i in range(7):
  s += max(d[i], j[i])
print(s)