a, b = map(int, input().split())
n = int(input())
x = [int(input()) for i in range(n)]

for xx in x:
  print(-1 if xx > b else 0 if a <= xx <= b else a - xx)