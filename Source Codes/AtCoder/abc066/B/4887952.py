def f(s):
  l=len(s)
  if l%2==0:
    return s[:l//2]==s[l//2:]
s=input()
L=len(s)
for i in range(1,L):
  a=s[:L-i]
  if f(a):
    ans=len(a)
    break
print(ans)