n=int(input())
s=list(input())
l=s[:n]
r=s[n:][::-1]
d={}
e={}
for i in range(1<<n):
  s=t=u=v=''
  for j in range(n):
    if (i>>j)&1:
      s+=l[j]
      t+=r[j]
    else:
      u+=l[j]
      v+=r[j]
  d[(s,u)]=d.get((s,u),0)+1
  e[(t,v)]=e.get((t,v),0)+1
a=0
for i in d.keys():
  a+=d[i]*e.get(i,0)
print(a)