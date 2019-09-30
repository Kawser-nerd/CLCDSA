

canons = []

def canonicalize(s):
    min_string = s
    for i in xrange(len(s)):
        s = s[1:] + s[0]
        if s < min_string:
            min_string = s
    return min_string

for i in xrange(2000005):
    canons.append(canonicalize(str(i)))

T = int(raw_input())
for i in xrange(T):
    counts = {}
    A, B = [int(x) for x in raw_input().split()]
    for j in xrange(A, B + 1):
        s = canons[j]
        if not counts.has_key(s):
            counts[s] = 0
        counts[s] += 1
    
    num = sum(counts[s] * (counts[s] - 1) / 2 for s in counts)
    print ('Case #%d: ' % (i + 1)) + str(num)
