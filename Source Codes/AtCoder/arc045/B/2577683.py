from itertools import accumulate

N, M = map(int, input().split())
S = [list(map(int, input().split())) for i in range(M)]
R = [0] * (N+2)

for s, t in S:
    R[s] += 1
    R[t+1] -= 1

R = list(accumulate(R))
R = [(1 if i >= 2 else 0) for i in R]
R = list(accumulate(R))

ans = []
index = 1
for s, t in S:
    if s == t and R[s-1] < R[t]:
        ans.append(index)
    else:
        if R[t]-R[s-1] == t-s+1:
            ans.append(index)
    index += 1

if ans:
    print(len(ans))
    print(*ans, sep="\n")
else:
    print(0)