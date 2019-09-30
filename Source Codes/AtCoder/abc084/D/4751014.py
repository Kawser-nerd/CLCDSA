from collections import defaultdict
Q = int(input())
queries = [tuple(map(int, input().split())) for i in range(Q)]

total = [0]
prime = defaultdict(lambda: True)
for i in range(2, 100001):
    for j in range(i * 2, 100001, i):
        prime[j] = False
for i in range(1, 50000):
    n = 2 * i + 1
    total.append(total[-1] + int(prime[n] and prime[(n + 1) // 2]))

for i in range(Q):
    l, r = queries[i][0], queries[i][1]
    if l == 1:
        print(total[(r - 1) // 2])
    else:
        print(total[(r - 1) // 2] - total[(l - 1) // 2 - 1])