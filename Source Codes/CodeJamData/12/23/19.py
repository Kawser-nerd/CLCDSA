tc = int(raw_input())

def fil_sum(p, l):
    return sum(l[i] for i in range(len(l)) if p & 2**i)

for t in range(1, tc+1):
    p = raw_input().split()
    n = int(p[0])
    p = map(int, p[1:])

    d = dict()

    print "Case #%d:" % t

    for i in range(2**n):
        s = fil_sum(i, p)
        if s in d:
            print " ".join(str(p[j]) for j in range(n) if d[s] & 2**j)
            print " ".join(str(p[j]) for j in range(n) if i & 2**j)
            break
        d[s] = i
    else:
        print "Impossible"

