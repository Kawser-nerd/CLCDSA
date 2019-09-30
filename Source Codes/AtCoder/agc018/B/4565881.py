import sys
from collections import Counter
input = sys.stdin.readline

n,m = map(int,input().split())
a = []
b = []
for i in range(n):
    a.append(tuple(map(lambda x:int(x)-1,input().split())))
    b.append(a[i][0])

used = [False]*m
idx = [0]*n

res = n
for i in range(m-1):
    ctr = Counter(b)
    d = ctr.most_common()
    p,num = d[0]
    res = min(res,num)
    used[p] = True

    for j in range(n):
        while used[a[j][idx[j]]]:
            idx[j] = idx[j] + 1
        b[j] = a[j][idx[j]]

print(res)