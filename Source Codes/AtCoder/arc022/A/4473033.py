def ans():
  S = input().lower()
  f = 0
  for s in S:
    if(s == "i" and f == 0):
      f = 1
    if(s == "c" and f == 1):
      f = 2
    if(s == "t" and f == 2):
      f = 3
  if(f == 3):
    print("YES")
  else:
    print("NO")
ans()