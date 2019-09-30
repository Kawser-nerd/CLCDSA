n = int(input())
lst = []
for _ in range(n):
  lst += [input()[::-1]]
lst.sort()
for s in lst:
  print(s[::-1])