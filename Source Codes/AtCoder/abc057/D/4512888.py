import math
N,A,B = map(int,input().split())
V = list(map(int,input().split()))
V.sort()
V.reverse()
cur = 0
selectlist = []
for i in range(A,B+1):
    S = 0
    for j in range(i):
        S += V[j]
    S = S/i
    if cur < S:
        cur = S
        selectlist = [i]
    elif cur == S:
        selectlist.append(i)
ans = 0
for p in range(len(selectlist)):
    nowselect = 1
    s = 0
    K = []
    for i in range(selectlist[p]):
        K.append(V[i])
    P = list(set(K))
    P.sort()
    P.reverse()
    for j in range(len(P)):
        cnt = V.count(P[j])
        s += cnt
        if s >= selectlist[p]:
            res = K.count(P[j])
            nowselect *= math.factorial(cnt)//(math.factorial(res)*math.factorial(cnt-res))
            ans += nowselect
        else:
            nowselect *= cnt
print(cur)
print(ans)