N,K,Q = a = map(int,input().split())
a = list(map(int,input().split()))
inf = 10**10
ans = inf
for i in range(N):
    small = a[i]
    seq = []
    seqq = []
    for j in range(N):
        if a[j] < small:
            seq.append(seqq)
            seqq = []
        else:
            seqq.append(a[j])
    seq.append(seqq)
    aaa = []
    for s in seq:
        if len(s)>=K:
            s.sort()
            aaa += s[:len(s)-K+1]
    if len(aaa)>=Q:
        aaa.sort()
        ans = min(ans,aaa[Q-1]-aaa[0])
print(ans)