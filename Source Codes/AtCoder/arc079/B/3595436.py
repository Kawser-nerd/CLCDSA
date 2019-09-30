k = int(input())
n = 50
print(n)

l = []
for i in range(n):
    tmp = [n+1-i]*i + [-i]*(n-i)
    l.append(tmp)

res = []
for i in range(n):
    res.append(k//n + i + l[k%n][i])
print(*res)

"""
for s in l:
    print(*s)
"""