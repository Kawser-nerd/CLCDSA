T=int(input())

def symh(m,k,c):
    for i in range(0,k):
        for j in range(k - i - 1, k + i, 2):
            s = 2 * c - j
            if k - i - 1 <= s < k + i and m[i][j] != m[i][s]:
                return False
    for i in range(k,2*k - 1):
        for j in range(i - k  + 1, 2 * k - i - 2, 2):
            s = 2 * c - j
            if i - k + 1 <= s < 2 * k - i - 2 and m[i][j] != m[i][s]:
                return False
    return True

def symv(m,k,c):
    for i in range(0,k):
        for j in range(k - i - 1, k + i, 2):
            s = 2 * c - j
            if k - i - 1 <= s < k + i and m[j][i] != m[s][i]:
                return False
    for i in range(k,2*k - 1):
        for j in range(i - k  + 1, 2 * k - i - 2, 2):
            s = 2 * c - j
            if i - k + 1 <= s < 2 * k - i - 2 and m[j][i] != m[s][i]:
                return False
    return True

for testCase in range(0,T):
    k = int(input())
    m = []
    for i in range(0,2 * k - 1):
        m.append(input())

    h = 0
    while h < k - 1:
        if symh(m, k, k - 1 + h) or symh(m, k, k - 1 - h):
            break
        h += 1
    v = 0
    while v < k - 1:
        if symv(m, k, k - 1 + v) or symv(m, k, k - 1 - v):
            break
        v += 1
    n = h + v
    print('Case #{0}: {1}'.format(testCase+1, n * (2 * k + n)))
