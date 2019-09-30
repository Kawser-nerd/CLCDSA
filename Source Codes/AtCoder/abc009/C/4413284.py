from collections import Counter

N,K = map(int, input().split())
s = input()
cand = sorted(s)
mismatch = 0
ans = ""
for i in range(N):
    count = Counter(s[:i+1]) - Counter(list(ans))
    sum_ = sum(count.values())
    for cj in list(cand):
        miss = mismatch + (cj != s[i])
        dif = sum_ - (count[cj] > 0)
        if miss + dif <= K:
            ans += cj
            cand.remove(cj)
            mismatch = miss
            break
print(ans)