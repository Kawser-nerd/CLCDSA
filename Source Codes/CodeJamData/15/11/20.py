import sys
sys.stdin = open('a.in', 'r')
sys.stdout = open('a.out', 'w')




def getline():
    return [int(c) for c in input().split()]


def solve():
    [n] = getline()
    a = getline()
    ans1 = 0
    ans2 = 0
    k = 0
    for i in range(0, n-1, 1):
        if a[i]>a[i+1]:
            ans1 += a[i]-a[i+1]
            k = max(k, a[i]-a[i+1])
    for i in range(0, n-1, 1):
        ans2 += min(a[i], k)

    return "%d %d" % (ans1, ans2)

    


for T in range(int(input())):
    sys.stderr.write(str(T))
    print('Case #%d: %s' % (T+1, solve()))