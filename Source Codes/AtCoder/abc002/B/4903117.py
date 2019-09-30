def mi(s):
  return s-1
t=input()
k=list(t)
b=[i for i, x in enumerate(k) if x=='a' or x=='i' or x=='u' or x=='e' or x=='o']
for y in range(len(b)):
  k.pop(b[0])
  b.pop(0)
  b=list(map(mi,b))
print(''.join(k))