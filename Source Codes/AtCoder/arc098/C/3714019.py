import bisect
N, K, Q = [int(i) for i in input().split()]
A = [(int(v),i) for i,v in enumerate(input().split())]
A.sort()
B = [0]*(N)
for i in range(N):
    B[A[i][1]] = i
C = [A[B[i]][0] for i in range(N)]
Candi = set(range(N))
ctr = 0
ans = []
rng = [-1,N]
while len(Candi) >= Q:
    T = sorted(Candi)
    ans.append((list(T)[0],list(T)[Q-1]))
    x = B.index(ctr)
    st = bisect.bisect_left(rng, x)
    Candi = Candi - set(sorted(B[rng[st-1]+1:x]+[2002],reverse = 1)[:K])\
    - set(sorted(B[x:rng[st]]+[2002],reverse = 1)[:K])- set([B[x]])
    bisect.insort_left(rng, x)
    ctr += 1
print(min([A[j][0]-A[i][0] for i,j in ans]))