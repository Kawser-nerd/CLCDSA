tcs = int(input())

binom = [[1]]
for i in range(1, 5001):
    binom.append([])
    binom[-1].append(binom[-2][0]/2)
    for j in range(1, i):
        binom[-1].append((binom[-2][j-1] + binom[-2][j])/2)
    binom[-1].append(binom[-2][-1]/2)

for i in range(len(binom)):
    assert(len(binom[i]) == i+1)
    for j in range(1, len(binom[i])):
        binom[i][j] += binom[i][j-1];

for tc in range(1, tcs+1):
    n, x, y = (int(i) for i in input().split(' '))

    level = (abs(x) + y) // 2

    l = 0
    while n > 0:
        k = 4*l + 1
        if n >= k:
            if level == l:
                print("Case #%d: 1.0" % tc)
                break
            n -= k
        else:
            if level == l:
                if y <= n - 1 - 2*l:
                    print("Case #%d: 1.0" % tc)
                elif y >= min(2*l, n):
                    print("Case #%d: 0.0" % tc)
                else:
                    print("Case #%d: %.15f" % (tc, 1 - binom[n][y]))
                break
            n = 0

        l += 1
    else:
        print("Case #%d: 0.0" % tc)

