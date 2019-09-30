s=input()
n=len(s)
a=0
for i,t in enumerate(s):
  if t=='U':
    a+=n-1-i+i*2
  else:
    a+=(n-1-i)*2+i
print(a)