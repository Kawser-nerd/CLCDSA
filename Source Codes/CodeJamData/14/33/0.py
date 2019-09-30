import sys

def readints():
    line = sys.stdin.readline().split()
    return [int(x) for x in line]

T, = readints()
for testcase in range(1,T+1):
    N, M, K = readints()

    if N == 1 or M == 1:
        soln = K
    elif K <= 3:
        soln = K
    else:
        corners = [0, 0, 0, 1]
        sides = [0, 1, 1, 0]
        # corners = [1, 1, 1, 1]
        # sides = [0, 0, 0, 0]
        w = 2
        h = 2

        def areawh(corners, sides):
            w = 1 + sides[2] + corners[1] + corners[2]
            h = 1 + sides[1] + corners[0] + corners[1]
            return w * h - sum(c * (c + 1) / 2 for c in corners), w, h

        def trycorner(idx, w, h, corners, sides):
            idx2 = (idx+1)%4
            #if w < M and sides[idx] > 0:
            corners[idx] -= 1
            sides[idx] += 1
            sides[idx2] += 1

            if idx%2 == 1:
                wh = [w-M,h-N]
            else:
                wh = [h-N,w-M]

            if wh[0] < 0 and sides[idx] == 2:
                sides[idx] -= 2
                corners[idx] += 1
                corners[(idx-1)%4] += 1
                wh[0] += 1

            if wh[1] < 0 and sides[idx2] == 2:
                sides[idx2] -= 2
                corners[idx2] += 1
                corners[idx] += 1
                wh[1] += 1
            AA = areawh(corners, sides)
            #print wh, "Awh", AA
            return areawh(corners, sides) + (corners, sides)


        #while 1:
        A, w, h = areawh(corners, sides)
        #for ii in range(6):
        while 1:
            stones = sum(corners) + sum(sides)
            print "%d/%d" % (stones, A), corners, sides, "%dx%d" % (w,h)

            if A >= K: break
            #mcor = max(corners)
            poss = []
            for idx in range(4):
                poss.append(trycorner(idx, w, h, corners[:], sides[:]))

                #if corners[idx] == mcor:

            poss.sort()
            A, w, h, corners, sides = poss[-1]
        
        soln = stones

    print "Case #%d: %d" % (testcase, soln)

