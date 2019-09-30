import sys
import collections

def concat_str(args):
    s = ""
    for arg in args:
        s += str(arg)
    return s

def debug(*args):
    sys.stderr.write(concat_str(args) + "\n")

def printf(*args):
    debug(*args)
    print concat_str(args)

def int_input():
    return map(int, raw_input().split(' '))

NTestCases = int(raw_input())

run = collections.namedtuple("run", ["length", "oid"])

def solve(N, M, boxes, toys):
    cached = [[-1 for i in range(M+1)] for j in range(N+1)]

    def rec(i, j):
        if i < 0 or j < 0:
            return 0

        if i == 0 or j == 0:
            cached[i][j] = 0
            return cached[i][j]

        if cached[i][j] != -1:
            return cached[i][j]

        box = boxes[i-1]
        toy = toys[j-1]

        oid = box.oid

        maxi = max(rec(i-1, j), rec(i, j-1))

        boxi = i - 1
        toyi = j - 1
        boxsum = 0
        toysum = 0

        if box.oid == toy.oid:
            while boxi != -1 or toyi != -1:
                if toyi == -1 or (boxsum <= toysum and not boxi == -1):
                    tbox = boxes[boxi]
                    if tbox.oid == oid:
                        boxsum += tbox.length
                        if min(toysum, boxsum) != 0:
                            maxi = max(maxi, min(toysum, boxsum) + rec(boxi, toyi+1))
                    boxi -= 1
                else:
                    ttoy = toys[toyi]
                    if ttoy.oid == oid:
                        toysum += ttoy.length
                        if min(toysum, boxsum) != 0:
                            maxi = max(maxi, min(toysum, boxsum) + rec(boxi+1, toyi))
                    toyi -= 1

        #toysum = 0
        #for ntoy in range(j-1, -1, -1):
        #    toy = toys[ntoy]
        #    if toy.oid == box.oid:
        #        toysum += toy.length
        #        if toysum > box.length:
        #            maxi = max(maxi, box.length + rec(i-1, ntoy))
        #            break
        #        maxi = max(maxi, toysum + rec(i-1, ntoy))


        cached[i][j] = maxi
        return cached[i][j]

    result = rec(N, M)

    return result

for n_test_case in range(NTestCases):
    N, M = int_input()

    raw = int_input()
    boxes = [run(raw[i*2], raw[i*2+1]) for i in range(N)]
    raw = int_input()
    toys = [run(raw[i*2], raw[i*2+1]) for i in range(M)]
    
    #boxes.reverse()
    #toys.reverse()

    debug("Solving case ", n_test_case + 1)

    printf("Case #", n_test_case + 1, ": ", str(solve(N, M, boxes, toys)))

