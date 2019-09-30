def inpl(): return [int(i) for i in input().split()]
from collections import defaultdict

A, B, C, D, E, F = inpl()
H = defaultdict(lambda: 0)
H[(0,0)] = 1
x = [(100*A, 0), (100*B, 0), (0, C), (0, D)]
flag = True
while flag:
    flag = False
    for i, j in x:
        for ni,nj in H.copy().keys():
            if i+j+ni+nj <= F and ni+i:
                if (nj+j)/(ni+i) <= E/100:
                    if not H[(i+ni, j+nj)]:
                        H[(i+ni, j+nj)] = 1
                        flag = True
anssw, anss = (100*A, 0)
for k, l in H.keys():
    if not k:
        continue
    if anss/anssw < l/(k+l):
        anssw, anss =k+l, l
print(anssw, anss)