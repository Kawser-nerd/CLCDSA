n, c, k = map(int, input().split())
T = sorted([int(input()) for i in range(n)])

p = 0
b = 0
for i in range(n):
    t = T[i]
    if p == 0:
        w = t
    p += 1

    if t - w > k:
        b += 1
        p = 1
        w = t    
    elif p == c or t - w == k:
        b += 1
        p = 0

    if i == n - 1 and p > 0:
        b += 1
    #print(t, w, p, b)
print(b)