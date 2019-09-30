#!/usr/bin/env python

import sys

input = sys.stdin

def checkHorizontal(d):
    for line in range(0, len(d)):
        l, r = 0, len(d[line]) - 1
        while l < r:
            if d[line][l] != d[line][r]:
                if d[line][l] == -1:
                    d[line][l] = d[line][r]
                elif d[line][r] == -1:
                    d[line][r] = d[line][l]
                else:
                    return False
            l += 1
            r -= 1
    return True

def checkVertical(d):
    for col in range(0, len(d)):
        l, r = 0, len(d) - 1
        while l < r:
            if col < len(d[l]) and col < len(d[r]):
                if d[l][col] != d[r][col]:
                    if d[l][col] == -1:
                        d[l][col] = d[r][col]
                    elif d[r][col] == -1:
                        d[r][col] = d[l][col]
                    else:
                        return False
            l += 1
            r -= 1
    return True

def solve(N, d):
    import copy
    global MIN
    for h in range(0, N + 1):
        newd = []
        length, delta = 1, 1
        added = 0
        for lin in range(1, h + 1):
            newd.append([-1 for col in xrange(length)])
            added += length
            length += delta
            if length == (N + h):
                delta = -1

        for lin in range(1, 2 * N):
            newLine = copy.copy(d[lin - 1])
            while len(newLine) < length:
                newLine.append(-1)
                added += 1
            newd.append(newLine)
            length += delta
            if length == (N + h):
                delta = -1

        for lin in range(1, h + 1):
            newd.append([-1 for col in xrange(length)])
            added += length
            length += delta
            if length == (N + h):
                delta = -1
        if added >= MIN:
            continue

        for v in range(0, N + h + 1):
            if added >= MIN:
                continue

            length, delta = 1, 1
            finD = copy.copy(newd)
            addedNow = added
            for lin in range(0, 2 * (N + h + v) - 2):
                if lin >= len(finD):
                    finD.append([])
                while len(finD[lin]) + 2 <= length:
                    finD[lin] = [-1] + finD[lin] + [-1]
                    addedNow += 2
                while len(finD[lin]) < length:
                    finD[lin].append(-1)
                    addedNow += 1

                length += delta
                if length == (N + h + v):
                    delta = -1
            if v:
                finD.append([-1])
                addedNow += 1
            if addedNow >= MIN:
                continue

#            print N, h, v
#            for line in finD:
#                print "\t", line

            if not checkHorizontal(finD):
                continue
#            print "horizontal ok"
#            for line in finD:
#                print "\t", line

            if not checkVertical(finD):
                continue
#            print "isOK"
#            print h, v
#            for line in finD:
#                output = "\t"
#                output += "    " * (((len(finD) + 1) / 2 - len(line)) / 2)
#                if len(line) % 2 != ((len(finD) + 1) / 2 % 2):
#                    output += "  "
#                output += "  ".join("%2d" % i for i in line)
#                print output
#
#            print addedNow
#            import time
#            time.sleep(1)
            MIN = min(MIN, addedNow)

def main():
    T = int(input.readline())
    for t in range(1, T + 1):
        N = int(input.readline())
        d = []
        for i in range(1, N * 2):
            d.append(map(int, input.readline().split()))

        global MIN
        MIN = 0x3f3f3f3f
        solve(N, d)
        for i in range(len(d)):
            d[i] = d[i][::-1]
        solve(N, d)
        d = d[::-1]
        solve(N, d)
        for i in range(len(d)):
            d[i] = d[i][::-1]
        solve(N, d)

        print "Case #%s: %s" % (t, MIN)

    return 0

if __name__ == "__main__":
    main()

