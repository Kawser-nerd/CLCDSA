d = {'1': {'1': '1', 'i': 'i', 'j': 'j', 'k': 'k'},
     'i': {'1': 'i', 'i': '1', 'j': 'k', 'k': 'j'},
     'j': {'1': 'j', 'i': 'k', 'j': '1', 'k': 'i'},
     'k': {'1': 'k', 'i': 'j', 'j': 'i', 'k': '1'},}
g = {'1': {'1':  1, 'i':  1, 'j':  1, 'k':  1},
     'i': {'1':  1, 'i': -1, 'j':  1, 'k': -1},
     'j': {'1':  1, 'i': -1, 'j': -1, 'k':  1},
     'k': {'1':  1, 'i':  1, 'j': -1, 'k': -1},}
def mul(a, sa, b, sb):
    return (d[a][b], sa * sb * g[a][b])

def solve():
    l, x = map(int, raw_input().split())
    s = raw_input().strip()
    cur = ('1', 1)
    tar = [('i', 1), ('k', 1)]
    j = 0
    for i in xrange(min(x, 8)):
        for c in s:
            cur = mul(cur[0], cur[1], c, 1)
            if j < 2 and cur == tar[j]:
                j += 1
    t = ('1', 1)
    for c in s:
        t = mul(t[0], t[1], c, 1)
    cur = ('1', 1)
    for i in xrange(x % 4):
        cur = mul(cur[0], cur[1], t[0], t[1])
    if j == 2 and cur == ('1', -1):
        return "YES"
    else:
        return "NO"

T = int(raw_input())
for i in xrange(T):
    print "Case #%d: %s" % (i + 1, solve())
