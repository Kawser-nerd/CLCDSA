import math
a=sorted(map(int,open(0).read().split()[1:]))
c=t=0
for b in a:t+=b;c+=t
print(c)
c=1
for s in set(a):c=c*math.factorial(a.count(s))%(10**9+7)
print(c)