n=int(input())
s=input()
ans=0
for i in range(1,n-1):
  a=set(s[:i])
  b=set(s[i:])
  n=len(a)+len(b)-len(a|b)
  ans=max(ans,n)
print(ans)