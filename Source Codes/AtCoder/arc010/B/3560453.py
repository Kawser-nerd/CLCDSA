from datetime import date,timedelta
d=date(year=2012,month=1,day=1)
v=0
st=set()

n=int(input())
for _ in range(n):
  a,b=map(int,input().split("/"))
  buf=date(year=2012,month=a,day=b)
  while 1:
    wd=buf.weekday()
    if wd!=5 and wd!=6 and not buf in st:
      st.add(buf)
      break
    buf+=timedelta(days=1)

ans=0
while d.year==2012:
  wd=d.weekday()
  if wd==5 or wd==6 or d in st:
    v+=1
  else:
    v=0
  ans=max(ans,v)
  d+=timedelta(days=1)

print(ans)