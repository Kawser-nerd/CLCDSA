s = 0
for i in range(3):
  a, b = map(int, input().split())
  s = s + a * b // 10

print(s)