N=int(input())
res=0.0
for _ in range(N):
  mon,sib=input().split()
  if sib=='JPY':
    res+=float(mon)
  elif sib=='BTC':
    res+=float(mon)*380000.0
print(res)