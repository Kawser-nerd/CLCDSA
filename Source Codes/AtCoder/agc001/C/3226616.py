n, k = map(int, input().split())

import sys

sys.setrecursionlimit(2000)

l = [[] for i in range(n)]
e = []
for i in range(n-1):
    a, b = map(int, input().split())
    l[a-1].append(b-1)
    l[b-1].append(a-1)
    e.append([a-1, b-1])

def first_search(first, depth):
    record = 0
    for i in l[first]:
        temp = search(first, i, depth-1)
        if record < temp:
            record = temp
    return record + 1

def search(before, now, depth):
    if depth <= 0:
        return 1
    else:
        ans = 1
        for i in l[now]:
            if before != i:
                ans += search(now, i, depth-1)
        return ans

ret = 0
if k%2 == 0:
    for i in range(n):
        temp = search(-1, i, k//2)
        if temp > ret:
            ret = temp
else:           
    for i in e:
        temp = search(i[0], i[1], k//2) + search(i[1], i[0], k//2)
        if temp > ret:
            ret = temp
        

print(n-ret)