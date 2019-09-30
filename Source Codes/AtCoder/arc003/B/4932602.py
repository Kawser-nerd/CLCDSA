n=int(input())
s=[input().strip()[::-1] for _ in range(n)]
for _s in sorted(s):
  print(_s[::-1])