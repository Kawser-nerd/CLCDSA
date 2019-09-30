from collections import Counter
n,c=[int(i) for i in input().split()]
a=[int(input()) for i in range(n)]
o=Counter(a[::2])
e=Counter(a[1::2])
if o.most_common()[0][0]!=e.most_common()[0][0]:
  print((n-o.most_common()[0][1]-e.most_common()[0][1])*c)
else:
  s0=0
  s1=0
  if len(e)==1 and len(o)==1:
    print(n//2 *c)
  else:
    if len(e)>=2:
      s0=o.most_common()[0][1]+e.most_common()[1][1]
    if len(o)>=2:
      s1=o.most_common()[1][1]+e.most_common()[0][1]
    print((n-max(s0,s1))*c)