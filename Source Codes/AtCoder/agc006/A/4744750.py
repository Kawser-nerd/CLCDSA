n,s,t=int(input()),input(),input();ans=2*n
for i in range(n):
  if i==0and s==t:ans=n
  elif s[i:]==t[:-i]:ans=min(ans,n+i)
print(ans)