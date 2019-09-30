a,b,x = map(int, input().split())

count = 0

if a % x == 0:
  count += 1

if b >= a + (x - a % x):
  p = b - a - (x - a % x)
  count += p // x + 1

print(count)