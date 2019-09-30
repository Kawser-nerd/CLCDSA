# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
N, C = map(int, input().split())
sushis = [list(map(int, input().split())) for _ in range(N)]

# A?????,B?????????
# O->A?0->A->O???????
# O->A????val(O->A[i]) > val(O->A[i+1])???i+1?????i???????.
# ???tmpMax??????????
valA = []
valArev = []
sumV = 0
tmpMax = -float('inf')

for d, v in sushis:
    sumV += v
    valArev.append(sumV-2*d)
    tmpMax = max(tmpMax, sumV-d)
    valA.append(tmpMax)

valB = []
valBrev = []
sumV = 0
tmpMax = -float('inf')
for d, v in reversed(sushis):
    sumV += v
    revD = C-d
    valBrev.append(sumV-2*revD)
    tmpMax = max(tmpMax, sumV-revD)
    valB.append(tmpMax)


# ???????????
ans = max(valA+valB+[0])
# O->A->O->B
# i=N-1?????????????????????
for i in range(N-1):
    ans = max(ans, valArev[i]+valB[N-i-2])  # ?????????????valB[N-i-2])

# O->B->O->A
for i in range(N-1):
    ans = max(ans, valBrev[i]+valA[N-i-2])
print(ans)