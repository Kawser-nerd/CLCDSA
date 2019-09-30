ttt = int(input())

for tti in range(ttt):
  print("Case #%d: " % (tti+1), end="")
  buf = input().split(" ")
  n = int(buf[0])
  m = int(buf[1])
  k = int(buf[2])
  wyn = k
  for i in range(3,n+1):
    for j in range(3,m+1):
      kam = i*j-4
      obw = (i-2)*2 + (j-2)*2
      poz = max(0,k-kam)
      if obw+poz < wyn:
        wyn = obw+poz
      if kam-k >= 2 and obw+poz-1 < wyn:
        wyn = obw+poz-1
      #print(i, j, obw, kam, poz)
  print(wyn)