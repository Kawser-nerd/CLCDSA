s=input()
r=1000
for i in range(len(s)-2):
  n=int(s[i:i+3])
  tmp=abs(753-n)
  if tmp<r:
    r=tmp
print(r)