testcases = int(raw_input())

import random

for tc in range(1, testcases+1):
    n, w, l = map(int, raw_input().split())
    r = map(int, raw_input().split())

    for t in range(10):
        places = list()
        for i in range(n):
            done1 = False
            for j in range(10):
                done2 = True
                x = random.randint(0, w)
                y = random.randint(0, l)
                # print i, x, y
                for k in range(len(places)):
                    if abs(x - places[k][0]) < r[i] + r[k] and \
                       abs(y - places[k][1]) < r[i] + r[k]:
                        done2 = False
                        break
                if done2:
                    places.append((x, y))
                    done1 = True
                    break
            if not done1:
                print "couldn't do it..."
                break
        else:
            break

    print "Case #%d: %s" % (tc, ' '.join(map(lambda (a, b): str(a) + ' ' + str(b), places)))

