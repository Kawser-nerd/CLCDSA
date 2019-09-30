from itertools import accumulate

N = int(input())
card = list(map(int, input().split()))

acc = list(accumulate(card))
s = acc[-1]
ans = float('inf')
for i in range(N-1):
    t = acc[i]
    a = s-t
    ans = min(ans, abs(t-a))
print(ans)