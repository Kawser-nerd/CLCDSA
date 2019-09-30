def next_permut(entry):
    m = len(entry)
    i = m-1
    while(i>0 and entry[i] < entry[i-1]):
        i -= 1
    if(i==0):
        entry.reverse()
        return False
    k = m - 1
    while(entry[k] < entry[i-1]):
        k -= 1
    entry[i-1], entry[k] = entry[k], entry[i-1]
    x = 0
    while(i + x < m - 1 -x):
        entry[i+x], entry[m-1-x] = entry[m-1-x], entry[i+x]
        x += 1
    return True

def comp_size(s):
    tot = 0
    last_seen = '%'
    for x in xrange(len(s)):
        if(s[x] != last_seen):
            last_seen = s[x]
            tot += 1
    return tot

def apply_permut(p, s):
    k = len(p)
    ns = [0]*len(s)
    for x in xrange(len(s)):
        ns[x] = s[p[x % k] + (x//k)*k]
    return ''.join(ns)

filename = "D-small-attempt0.in"
f = open(filename, 'r')
of = open("D-small.out", 'w')

N = int(f.readline())

for x in xrange(N):
    k = int(f.readline())
    S = f.readline().strip()
    t = 1000000000
    p = [i for i in xrange(k)]
    t = min(t, comp_size(apply_permut(p, S)))
    while(next_permut(p)):
        t = min(t, comp_size(apply_permut(p, S)))
    print >> of, "Case #%d: %d" % (x + 1, t)



