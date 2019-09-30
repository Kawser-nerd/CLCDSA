N, K, Q = map(int, input().split())
a = list(map(int, input().split()))
ans = float("inf")
for i in range(N):
    tmp = []
    rec = []
    for j in range(N):
        if a[i] <= a[j]:
            tmp.append(a[j])
        else:
            if len(tmp) >= K:
                tmp = sorted(tmp)
                rec += tmp[:len(tmp) - K + 1]
            tmp = []

    if len(tmp) >= K:
        tmp = sorted(tmp)
        rec += tmp[:len(tmp) - K + 1]
    if Q <= len(rec):
        rec = sorted(rec)
        ans = min(ans, rec[Q - 1] - rec[0])
print(ans)