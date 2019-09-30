import sys

tn = int(sys.stdin.readline())

for ti in xrange(tn):
    a, b = map(list, sys.stdin.readline().strip().split())
    n = len(a)
    best = (2**80, '', '')
    def bt(k, an):
        global best
        if k == len(a):
            i = int(''.join(a))
            j = int(''.join(b))
            d = abs(i - j)
            if d < best[0] or (d == best[0] and (i < int(best[1]) or (i == int(best[1]) and j < int(best[2])))):
                best = (d, ''.join(a), ''.join(b))
            return
        if a[k] == '?':
            if b[k] == '?':
                if an == 0:
                    a[k] = b[k] = '0'
                    bt(k+1, 0)
                    a[k] = '1'
                    bt(k+1, 1)
                    a[k] = '0'
                    b[k] = '1'
                    bt(k+1, -1)
                elif an > 0:
                    a[k] = '0'
                    b[k] = '9'
                    bt(k+1, 1)
                else:
                    a[k] = '9'
                    b[k] = '0'
                    bt(k+1, -1)
                a[k] = b[k] = '?'
            else:
                if an == 0:
                    a[k] = b[k]
                    bt(k+1, 0)
                    if b[k] != '0':
                        a[k] = chr(ord(b[k])-1)
                        bt(k+1, -1)
                    if b[k] != '9':
                        a[k] = chr(ord(b[k])+1)
                        bt(k+1, 1)
                elif an > 0:
                    a[k] = '0'
                    bt(k+1, 1)
                else:
                    a[k] = '9'
                    bt(k+1, -1)
                a[k] = '?'
        else:
            if b[k] == '?':
                if an == 0:
                    b[k] = a[k]
                    bt(k+1, 0)
                    if a[k] != '0':
                        b[k] = chr(ord(a[k])-1)
                        bt(k+1, 1)
                    if a[k] != '9':
                        b[k] = chr(ord(a[k])+1)
                        bt(k+1, -1)
                elif an > 0:
                    b[k] = '9'
                    bt(k+1, 1)
                else:
                    b[k] = '0'
                    bt(k+1, -1)
                b[k] = '?'
            else:
                if an == 0:
                    bt(k+1, 1 if ord(a[k]) > ord(b[k]) else (-1 if ord(a[k]) < ord(b[k]) else 0))
                else:
                    bt(k+1, an)
    bt(0, 0)
    print 'Case #{0}:'.format(ti+1), best[1], best[2]
