def withoutDuplication(s):
    res = []
    prev = -1
    for c in s:
        i = ord(c) - ord('a')
        if i != prev:
            res.append(i)
            prev = i
    return res

mod = 1000000007

def fact(n):
    if n <= 1:
        return 1
    return n*fact(n-1)%mod

def solve(strs):
    n = 26
    inE, outE, midE, badE = [0]*n, [0]*n, [0]*n, [0]*n
    g = [-1]*n
    for s in strs:
        letters = withoutDuplication(s)
        if len(letters) == 1:
            midE[letters[0]] += 1
        else:
            outE[letters[0]] += 1
            inE[letters[-1]] += 1
            g[letters[0]] = letters[-1]
            for c in letters[1:-1]:
                badE[c] += 1
 #   print inE[:4], outE[:4], midE[:4], badE[:4], g[:4]
    for i in xrange(n):
        if badE[i] > 0 and inE[i] + outE[i] + midE[i] + badE[i] > 1:
            return 0
        if inE[i] > 1 or outE[i] > 1:
            return 0
    seen, nc = [False]*n, 0
    for i in xrange(n):
        if seen[i] or inE[i] != 0:
            continue
        if outE[i] + midE[i] > 0:
            nc += 1
        t = i
        while t != -1:
            seen[t] = True
            t = g[t]
    if len(filter(None, seen)) < n:
        return 0
    #print nc
    res = fact(nc)
    for i in xrange(26):
        res *= fact(midE[i])
    return res%mod

T = int(raw_input())
for z in xrange(T):
    n = int(raw_input())
    s = raw_input().strip().split(' ')
    print "Case #%d: %s" % (z+1, solve(s))