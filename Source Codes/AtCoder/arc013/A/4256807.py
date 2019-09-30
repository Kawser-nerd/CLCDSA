import itertools
from functools import reduce
nml=list(map(int,input().split()))
pqro=list(map(int,input().split()))

pqrs=itertools.permutations(pqro)
ans = 0
for pqr in pqrs:
    num = reduce(lambda x,y:x*y,list(map(lambda x,y:x//y,nml,pqr)))
    ans = max(ans,num)
print(ans)