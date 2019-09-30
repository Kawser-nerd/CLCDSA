# Instructions: run main().

import sys

def main():
    problemLetter = 'B'
    #filePrefix = '%s-sample' % problemLetter
    #filePrefix = '%s-small-attempt0' % problemLetter
    filePrefix = '%s-large' % problemLetter
    fin = open(filePrefix + '.in', 'r')
    fout = open(filePrefix + '.out', 'w')
    #fout = sys.stdout
    caseCount = int(fin.readline().strip())

    for caseIx in xrange(caseCount):
        N, M = [int(s) for s in fin.readline().strip().split()]
        #print "N: %d, M: %d" % (N, M)
        S, W, T = [], [], []
        for r in range(N):
            nums = [int(s) for s in fin.readline().strip().split()]
            S.append([nums[3 * i] for i in xrange(M)])
            W.append([nums[3 * i + 1] for i in xrange(M)])
            T.append([nums[3 * i + 2] for i in xrange(M)])
        t = tim(N, M, S, W, T)


        fout.write('Case #%d: %d\n' % (caseIx + 1, t))


    fin.close()
    if fout != sys.stdout: fout.close()



def tim(N, M, S, W, T):
    NN, MM = 2*N, 2*M
    tims, fixed = [], []
    for r in xrange(NN):
        tims.append([None] * MM)
        fixed.append([False] * MM)
    tims[NN-1][0] = 0
    iter = 0
    #print_tims(tims, iter)
    while not fixed[0][MM-1]:
        i, j, t = least_unfixed(NN, MM, tims, fixed)
        SS, WW, TT = S[i/2][j/2], W[i/2][j/2], T[i/2][j/2]
        fixed[i][j] = True
        for di in (-1, 1):
            i2 = i + di
            if i2 > -1 and i2 < NN:
                t2 = get_tim(SS, WW, TT, i, j, t, i2, j)
                if (tims[i2][j] == None) or (t2 < tims[i2][j]):
                    tims[i2][j] = t2

        for dj in (-1, 1):
            j2 = j + dj
            if j2 > -1 and j2 < MM:
                t2 = get_tim(SS, WW, TT, i, j, t, i, j2)
                if (tims[i][j2] == None) or (t2 < tims[i][j2]):
                    tims[i][j2] = t2
        iter += 1
        #print_tims(tims, iter)
        
    return tims[0][MM-1]


def print_tims(tims, iter):
    print 'Iter %d' % iter
    for tt in tims:
        print tt
    print ''
    


def least_unfixed(NN, MM, tims, fixed):
    imin, jmin, tmin = None, None, None
    for i in xrange(NN):
        for j in xrange(MM):
            if (not fixed[i][j]) and (tims[i][j] != None):
                if (tmin == None) or (tims[i][j] < tmin):
                    imin, jmin, tmin = i, j, tims[i][j]
    #print 'least_unfixed returns %s' % ((imin, jmin, tmin),)
    return imin, jmin, tmin


def get_tim(SS, WW, TT, i1, j1, t, i2, j2):
    #print "get_tim(%d, %d, %d, %d, %d, %d, %d, %d)" % \
    #    (SS, WW, TT, i1, j1, t, i2, j2)
    ret = None
    if ( (i1 % 2 == 0 and i2 < i1) or
         (i1 % 2 == 1 and i2 > i1) or
         (j1 % 2 == 0 and j2 < j1) or
         (j1 % 2 == 1 and j2 > j1) ):
        ret = t + 2
    else:
        if i1 == i2: # horiz
            ret = next_green(t, WW, SS, TT + SS) + 1
        else:
            ret = next_green(t, SS, WW, TT) + 1
    #print "get_tim returns %d " % ret
    return ret
            

def next_green(t, gtime, rtime, stime):
    #print "next_green(%d, %d, %d, %d)" % (t, gtime, rtime, stime)
    dt = (t - stime) % (gtime + rtime)
    if dt < gtime:
        ret = 0
    else:
        ret = rtime + gtime - dt
    ret += t
    #print "next_green returns %d" % ret
    return ret



    
