#C Bugged
import numpy as np
a = int(input())
k   = []
k10 = []
s = 0
 
for j in range(a):
    i = int(input())
    if i % 10 == 0:
        k10.append(i)
        s += i
    else:
        k.append(i)
k.sort()
c = np.array(k)
l = c.sum()
if l%10==0 and len(k) !=0:
    l = l - c[0]
    s = s + l
elif len(k) == 0:
    s = 0
else:
    s = s + l
print(s)