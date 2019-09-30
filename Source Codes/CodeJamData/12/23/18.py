# -*- coding: utf-8 -*-
import sys
fin = sys.stdin
T = int(fin.readline())
for case in range(1,T+1):
    line = map(int, fin.readline().split())
    N = line[0]
    points = line[1:]
    points.sort()

    numbers = {0: []}

    result = None
    for n in points:
        for a, prefix in numbers.items():
            b = a + n
            seq = prefix + [n]
            if b in numbers:
                line2 = numbers[b]
                result = (seq, line2)
                break
            else:
                numbers[b] = seq
        if result:
            break
    #print numbers


    print "Case #%d:" % (case)
    if result:
        print " ".join(map(str, result[1]))
        print " ".join(map(str, result[0]))
    else:
        print "Impossible"


