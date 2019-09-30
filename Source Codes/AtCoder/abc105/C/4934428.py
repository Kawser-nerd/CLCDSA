N = int(input())
if N == 0:
  print(0)
else:
  ans = ""
  x = 0
  keta = 0
  while x != N:
    if (N - x) % 2 ** (keta + 1)== 0:
      ans = "0" + ans
    else:
      ans = "1" + ans
      x += (-2) ** keta
    keta += 1
  
  print(ans)