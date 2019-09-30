N,A,B = map(int,input().split())
now = 0
for i in range(N):
  s,d = input().split()
  if s=="East":
    if int(d)<A:
      now+=A
    elif int(d)>B:
      now+=B
    else:
      now+=int(d)
  else:
    if int(d)<A:
      now-=A
    elif int(d)>B:
      now-=B
    else:
      now-=int(d)
if now>0:
      print("East"+" "+str(now))
elif now<0:
      print("West"+" "+str(abs(now)))
else:
      print(0)