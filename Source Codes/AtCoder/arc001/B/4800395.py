a, b = map(int, input().split())
if a < b:
  minab, maxab = a, b
else:
  minab, maxab = b, a

ans = 0
while maxab - minab >= 10:
  ans += 1
  maxab -= 10

abd = maxab - minab
if abd == 0:
  print(ans)
elif abd == 1 or abd == 2 or abd == 3:
  print(ans + abd)
elif abd == 4 or abd == 6 or abd == 9:
  print(ans + 2)
elif abd == 5:
  print(ans + 1)
elif abd == 7 or abd == 8:
  print(ans + 3)