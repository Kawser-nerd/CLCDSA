s=input()
n=len(s)
v=n
for k in range(n-1):
  if s[k]!=s[k+1]:
    v=min(v,max(k+1,n-k-1))
print(v)