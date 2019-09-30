from collections import Counter as C

n = int(input())
a = list(map(int,input().split()))
a = sorted(a)
c = C(a)

res = 0
d = (dict(c))
for k in list(c):
    #print(k,d[k])
    if d[k]<k:
        res += d[k]
    else:
        res += d[k] - k
print(res)