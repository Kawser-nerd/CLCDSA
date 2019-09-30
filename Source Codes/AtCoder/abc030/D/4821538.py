n, m = map(int, input().split())
k = int(input())
a = list(map(lambda x: int(x) - 1, input().split()))

b = []
i = m - 1

#print(a)

while 1:
    #print(b)
    if i in b:
        c = b.index(i)
        MOD = len(b) - c
        break
    else:
        b.append(i)
        i = a[i]

if len(b) > k:
    print(b[k] + 1)
else:
    k = (k - c) % MOD
    print(b[c+k] + 1)