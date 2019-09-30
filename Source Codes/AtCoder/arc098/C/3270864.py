from collections import defaultdict
N, K, Q = map(int, input().split())
A = list(map(int, input().split()))
A_sorted = sorted(A)
ans = float("inf")
ap = 0
for i, a in enumerate(A_sorted):
    if a==ap:
        continue
    ap = a
    L = [0]
    d = defaultdict(list)
    for aa in A:
        if aa < a:
            if L[-1]==0:
                continue
            else:
                L.append(0)
        else:
            L[-1]+=1
            d[aa].append(len(L)-1)
    cnt = 0
    aap = 0
    for aa in A_sorted[i:]:
        if aap==aa: continue
        aap = aa
        for v in d[aa]:
            if L[v] >= K:
                L[v] -= 1
                cnt += 1
        if cnt >= Q:
            break
    else:
        break
    ans = min(ans, aa-a)
print(ans)