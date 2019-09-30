N, K = map(int, input().split())
best = [0] * N
not_best = []
for _ in range(N):
    t, d = map(int, input().split())
    if best[t-1] != 0:
        not_best.append(min(d, best[t-1]))
    best[t-1] = max(d, best[t-1])
best = [x for x in best if x != 0]
best.sort(reverse=True)
not_best.sort(reverse=True)
acc_best = [0] * (N + 1)
acc_not_best = [0] * (N + 1)
for i in range(len(best)):
    acc_best[i+1] = acc_best[i] + best[i]
for i in range(len(not_best)):
    acc_not_best[i+1] = acc_not_best[i] + not_best[i]
cand = []
for x in range(1, K+1):
    if x > len(best):
        break
    if K - x > len(not_best):
        continue
    cand.append(acc_best[x] + acc_not_best[K-x] + x**2)
print(max(cand))