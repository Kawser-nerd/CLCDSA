from collections import Counter
N,K = map(int,input().split())
A = list(map(int,input().split()))
ctr = Counter(A)

ans = 0
for i,(k,v) in enumerate(ctr.most_common()):
    if i < K: continue
    ans += v
print(ans)