N = int(input())
a = list(map(int,input().split()))
pos_max = max(a)
neg_max = min(a)
res = []
if abs(pos_max) >= abs(neg_max):
    # pos_max ? ??????
    pos = a.index(pos_max) + 1
    for i in range(N):
        a[i] += pos_max
        res.append([pos, i + 1])
    # ?????
    for i in range(N-1):
        a[i+1] += a[i]
        res.append([i + 1, i + 2])
else:
    # neg_max ? ??????
    pos = a.index(neg_max) + 1
    for i in range(N):
        a[i] += neg_max
        res.append([pos, i + 1])
    # ?????
    for i in range(N-2,-1,-1):
        a[i] += a[i+1]
        res.append([i + 2, i + 1])

# print(*a)
print(len(res))
for l in res:
    print(*l)