N=int(input())

import math
X=math.ceil(math.sqrt(N))

FACT=[]
for i in range(1,X+1):
    if N%i==0:
        FACT.append(i)

ANS=10**10

for f in FACT:
    x=N//f
    ANS=min(ANS,max(len(str(x)),len(str(f))))

print(ANS)