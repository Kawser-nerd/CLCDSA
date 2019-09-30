n=int(input())
z=[list(map(int,input().split()))for _ in[0]*n]
r=0
for i,(a,b)in enumerate(z):
  for j,(c,d)in enumerate(z[i+1:],i+1):
    c-=a
    d-=b
    for e,f in z[j+1:]:
      e-=a
      f-=b
      t=abs(c*f-d*e)
      r+=t and t%2<1
print(r)