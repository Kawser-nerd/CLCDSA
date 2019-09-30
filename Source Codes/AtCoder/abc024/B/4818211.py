n, t = map(int, input().split())
door = [int(input()) for i in range(n)]
total = 0

for i, v in enumerate(door):
  total += t
  if i != 0 and door[i - 1] + t >= v:
    total -= (t + door[i - 1] - v)

print(total)