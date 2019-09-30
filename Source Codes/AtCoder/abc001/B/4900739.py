m = float(input())
km = m / 1000
VV = 0
if 0.1 <= km <= 5:
 VV = str(int(km * 10))
 if len(VV) == 1:
  print(0,int(VV),sep="")
 else:
  print(int(km * 10))
if 6 <= km <= 30: 
 print(int(km+50))
if 35 <= km <= 70:
 print(int(((km-30)/5)+80))
if km > 70:
 print(89)
if km < 0.1:
 print(0,0,sep="")