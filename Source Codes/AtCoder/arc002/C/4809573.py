from itertools import product
from itertools import combinations
N = int(input())
C = input()

ss = list(product('ABXY',repeat=2))
ans = N
for l,r in combinations(ss,2):
    i = tmp = 0
    while i < N-1:
        if l[0]==C[i] and l[1]==C[i+1]:
            tmp += 1
            i += 2
        elif r[0]==C[i] and r[1]==C[i+1]:
            tmp += 1
            i += 2
        else:
            tmp += 1
            i += 1
    if i==N-1: tmp += 1
    ans = min(ans, tmp)
print(ans)