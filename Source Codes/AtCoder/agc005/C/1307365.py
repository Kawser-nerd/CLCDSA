def solve():
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    mina=a[0]
    maxa=a[-1]
    if (a[-1]+1) // 2 != mina:
        return False

    b=[0]*n
    for v in a:
        b[v] += 1
    if (maxa & 1) > 0:
        if b[mina] != 2:
            return False
    elif b[mina] != 1:
        return False

    for v in range(mina+1, maxa+1):
        if b[v] < 2:
            return False
    return True

print('Possible' if solve() else 'Impossible')