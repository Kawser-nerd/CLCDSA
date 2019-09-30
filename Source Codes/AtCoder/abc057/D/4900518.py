N,A,B=map(int,input().split())
V=list(map(int,input().split()))

V.sort(reverse=True)

AVERAGE=V[:A]

print(sum(AVERAGE)/A)

MIN=AVERAGE[-1]

MINUSE=0
for a in AVERAGE:
    if a==MIN:
        MINUSE+=1

MAXUSE=0
for a in V[:B]:
    if a==MIN:
        MAXUSE+=1

ALLUSE=0
for a in V:
    if a==MIN:
        ALLUSE+=1

import math

if V[0]!=MIN:
    print(math.factorial(ALLUSE)//math.factorial(MINUSE)//math.factorial(ALLUSE-MINUSE))

else: 
    ANS=0
    for use in range(MINUSE,MAXUSE+1):
            ANS+=math.factorial(ALLUSE)//math.factorial(use)//math.factorial(ALLUSE-use)

    print(ANS)