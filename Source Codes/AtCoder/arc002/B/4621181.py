n=input()
y,m,d=int(n[0]+n[1]+n[2]+n[3]),int(n[5]+n[6]),int(n[8]+n[9])
D=[31,28,31,30,31,30,31,31,30,31,30,31]
def uruu():
  global y,m
  if m==2:
    if y%400==0:return 1
    elif y%100==0:return 0
    elif y%4==0:return 1
    else:return 0
  return 0
while 1:
  if y/(m*d)%1==0:break
  d+=1
  if d>D[m-1]+uruu():
    d=1
    m+=1
    if m==13:
      m=1
      y+=1
if m>9 and d>9:print(str(y)+"/"+str(m)+"/"+str(d))
elif m>9:print(str(y)+"/"+str(m)+"/0"+str(d))
elif d>9:print(str(y)+"/0"+str(m)+"/"+str(d))
else:print(str(y)+"/0"+str(m)+"/0"+str(d))