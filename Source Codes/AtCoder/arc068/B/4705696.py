n = int(input())
a = set(input().split())
if len(a) % 2:
  print(len(a))
else:
  print(len(a)-1)