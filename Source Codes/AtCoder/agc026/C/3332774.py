N=int(input())
s=input()

sa=s[:N]
sb=s[N:]

import itertools
ALLIST=list(itertools.product((0,1),repeat=N))

from collections import defaultdict
STRA = defaultdict(int)
STRB = defaultdict(int)

for i in ALLIST:
    red_a=""
    blue_a=""
    red_b=""
    blue_b=""
    for j in range(N):
        if i[j]==0:
            red_a+=sa[j]
            red_b+=sb[j]
        else:
            blue_a+=sa[j]
            blue_b+=sb[j]

    STRA[(red_a[::-1],blue_a[::-1])]+=1
    STRB[(red_b,blue_b)]+=1

ANS=0
for key in STRA:
    ANS+=STRA[key]*STRB[key]

print(ANS)