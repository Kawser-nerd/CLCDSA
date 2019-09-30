n = int(input())
l = []
for _ in range(n):
  l.append(input()[::-1])
l.sort()
for i in l:
  print(i[::-1])