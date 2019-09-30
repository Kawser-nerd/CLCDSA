from collections import Counter

N, T = map(int, input().split())
As = list(map(int, input().split()))

T //= 2
profits = [0] * (N - 1)
minA = As[0]
for i, A in enumerate(As[1:]):
    profits[i] = T * (A - minA)
    minA = min(minA, A)

cnts = Counter(profits)
print(cnts[max(cnts.keys())])