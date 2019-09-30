n = int(input())
pi = 3.141592653589
arr = sorted([int(input()) for i in range(n)])

if n % 2 == 1:
  arr = [v** 2 if i % 2 == 0 else -1 * (v**2) for i, v in enumerate(arr)]
else:
  arr = [v** 2 if i % 2 == 1 else -1 * (v**2) for i, v in enumerate(arr)]

print(sum(arr) * pi)