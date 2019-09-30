from itertools import accumulate
N, K = map(int, input().split())
a = [0]+[int(i) for i in input().split()]
b = list(accumulate(a))
ans = 0
for x, y in zip(b, b[K:]):
    ans += y-x
print(ans)