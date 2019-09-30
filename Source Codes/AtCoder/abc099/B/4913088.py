a, b = map(int, input().split())
d = b - a
h = 0
for i in range(d):
  h += i+1
print(h - b)