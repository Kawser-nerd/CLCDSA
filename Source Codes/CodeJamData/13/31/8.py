import sys

vowels = ['a', 'e', 'i', 'o', 'u']

def countCons(S, n):
    res = 0
    cnt = 0
    for s in S:
        if s in vowels:
            if res <= 0:
                cnt = 0
        else:
            cnt += 1
        if cnt >= n:
            res += 1
    return res
    
T = int(sys.stdin.readline())
for ca in xrange(1, T+1):
    [S, n] = [v for v in sys.stdin.readline().split(" ")]
    n = int(n)
    ls = len(S)
    ans = 0
    for i in range(ls):
        ans += countCons(S[i:], n)
    
    print "Case #%d: %d" % (ca, ans)

