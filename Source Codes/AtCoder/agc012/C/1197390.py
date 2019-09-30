def ncr(n, r):
    r = min(n - r, r)
    up = 1
    down = 1
    for i in range(r):
        up *= (n - i)
        down *= (i + 1)
    return up // down


def seq(x):
    s = 0
    for i in range(1, x):
        j = i * 2
        if j > x:
            break
        s += ncr(x, j)
    return s


def ins(total, p):
    s = 0
    for i in range(p + 1):
        s += ncr(p, i) * ncr(total - p, i)
    return s

ans = []
N = int(input())
k = 1

for i in range(41, 0, -1):
    x = seq(i)
    if N >= x:
        for j in range(i):
            ans.append(k)
        N -= x
        k += 1
        break

size = len(ans)
s = size // 2
while N > 90:
    m = 0
    t = 0
    for i in range(s + 1):
        tmp = ins(size, i)
        if tmp > N:
            break
        if tmp > t:
            t = tmp
            m = i
    N -= t
    ans.insert(m, k)
    ans.append(k)
    k += 1

while N > 0:
    for i in range(41, 0, -1):
        x = seq(i)
        if N >= x:
            for j in range(i):
                ans.append(k)
            N -= x
            k += 1
            break
print(len(ans))
print(" ".join([str(x) for x in ans]))