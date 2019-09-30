a = list(input())
n = len(a)
if n == 1:
    print(0)
    exit()
res = 0
if n % 2 == 1:
    k = n//2
    judge = True
    for i in range(k):
        if a[i] != a[n-1-i]:
            judge = False
            break
    if judge:
        res = 0
    else:
        res = 25
    a = a[:k:]+a[k+1::]
    n -= 1
d = 0
k = n//2
for i in range(k):
    if a[i] != a[n-1-i]:
        d += 1
for i in range(k):
    if d >= 2:
        res += 50
    elif d == 1:
        if a[i] == a[n-1-i]:
            res += 50
        else:
            res += 48
    else:
        res += 50
print(res)