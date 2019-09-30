from collections import Counter

N,M = map(int,input().split())
src = [list(map(lambda x:int(x)-1,input().split())) for i in range(N)]

removed = [0] * M
idxes = [0] * N
ans = N
for _ in range(M-1):
    ctr = Counter([src[i][idxes[i]] for i in range(N)])
    k,most = ctr.most_common(1)[0]
    ans = min(ans, most)
    removed[k] = 1
    for i in range(N):
        while removed[src[i][idxes[i]]]:
            idxes[i] += 1
print(ans)