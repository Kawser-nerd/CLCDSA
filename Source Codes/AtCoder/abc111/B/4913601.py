N = int(input())

rev1 = (N//100) * 100 + (N//100) * 10 + (N//100)
rev2 = (N//100 +1) * 100 + (N//100+1) * 10 + (N//100+1)

if N <= rev1 <= rev2:
  print(rev1)
else:
  print(rev2)