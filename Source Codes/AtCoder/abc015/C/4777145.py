import itertools

n, k = map(int, input().split())

t = [[] for i in range(n)]

for i in range(n):
    q = list(map(int, input().split()))
    for j in range(k):
        t[i].append(q[j])

flag = False

for iter in itertools.product([i for i in range(k)], repeat = n):
    xor = 0
    for idx, value in enumerate(iter):
        xor ^= t[idx][value]
    if xor == 0:
        flag = True
        break

print("Found" if flag else "Nothing")