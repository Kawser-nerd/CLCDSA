k, s = map(int, input().split())
c = 0
for x in range(k+1):
    for y in range(k+1):
        if ((s-x-y) <= k) & ((s-x-y) >= 0):
            c += 1
print(c)