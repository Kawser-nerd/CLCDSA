import fileinput
import math

fitr = iter (fileinput.input())

for case in range (int(fitr.next())):
    N = int(fitr.next())
    M = int(fitr.next())
    L = []

    for i in range(M):
        line = [int(x) for x in fitr.next().split()]
        l = []
        for j in range(line[0]):
            l.append((bool(line[1+2*j+1]), line [1+2*j]))
        l.sort()
        L.append(l)

    malted = set()
    impossible = False
    available_cust = set(range(M))

    old_len = 0
    while len(available_cust) != old_len and not impossible:
        old_len = len(available_cust)
        for i in available_cust.copy():
            placed = False
            for (m, f) in L[i]:
                if m:
                    malted.add(f)
                    available_cust.discard(i)
                    placed = True
                    break
                else:
                    if f not in malted:
                        placed = True
                        break

            if not placed:
                impossible = True
                break
                
    if impossible:
        output = 'IMPOSSIBLE'
    else:
        output = ' '.join([str(int(f in malted)) for f in range(1, N+1)])

    print 'Case #%d: %s' % (case + 1, output)
