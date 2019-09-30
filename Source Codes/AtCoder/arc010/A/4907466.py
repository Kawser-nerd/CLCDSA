import sys

n, m, a, b = map(int, input().split())

for i in range(m):
  x = int(input())
  
  if n <= a:
    n = n + b
  
  n = n - x
  if n < 0:
    print(i + 1)
    sys.exit()

print("complete")