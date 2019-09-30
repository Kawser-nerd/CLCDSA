from itertools import accumulate
N, K = map(int, input().split())
a = [0]+list(map(int, input().split()))

acc = list(accumulate(a))
acc2 = list(accumulate(map(lambda x: x if x > 0 else 0, a)))
ans, total = 0, acc2[-1]

for i, j in zip(range(1, N+1), range(K, N+1)):
    v = total - acc2[j] + acc2[i-1] + (acc[j] - acc[i-1] if acc[j] - acc[i-1] > 0 else 0)
    if ans < v:
        ans = v

print(ans)