N ,Q = map(int ,input().split())
L = [0 for _ in range(N+10)]
for _ in range(Q):
    x,y = map(int,input().split())
    L[x] += 1
    L[y+1] -= 1
import itertools as it
L= list(it.accumulate(L))
del L[0]
for i in range(N):
    print(L[i] % 2,end='')
print()