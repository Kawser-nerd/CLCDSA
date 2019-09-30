n = int(input())
sum1 = 0
ti = float("inf")
for i in range(n):
  a,b = map(int,input().split())
  if a > b:
    ti = min(ti,b)
  sum1 += a
if ti == float("inf"):
  print(0)
else:
  print(sum1 - ti)