import sys
from itertools import accumulate

inf = 1<<60
ans = 0

def solve():
    n, k = map(int, sys.stdin.readline().split())
    a = [int(sys.stdin.readline().rstrip()) - k for i in range(n)]
    s = [0] + list(accumulate(a))

    MergeSort(s)

    print(ans)

def MergeSort(a):
    if len(a) == 1:
        return a

    apre = MergeSort(a[:len(a)//2])
    asuf = MergeSort(a[len(a)//2:])

    res = merge(apre, asuf)

    return res

def merge(a, b):
    global ans
    na = len(a)
    nb = len(b)

    a.append(-inf)
    b.append(-inf)

    la = 0
    lb = 0

    res = []

    for i in range(na + nb):
        if a[la] <= b[lb]:
            ans += na - la
            res.append(b[lb])
            lb += 1
        else:
            res.append(a[la])
            la += 1

    return res

if __name__ == '__main__':
    solve()