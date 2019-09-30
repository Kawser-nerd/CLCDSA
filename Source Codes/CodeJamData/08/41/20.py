#!/usr/bin/python
import sys
import copy

##szfile = './A-small-attempt0.in.txt'
##szfile_output = './A-small.output.txt'

szfile = './A-large.in.txt'
szfile_output = './A-large.output.txt'
##szfile = './B-small.in.txt'
##szfile_output = './B-small.output.txt'


class BTree:
    def __init__(self):
        pass

    def RunFile(self) :
# using file set
        f = open(szfile,'rb')
        fw = open(szfile_output,'wb')
# ---
        szline = f.readline()
        ncase = int(szline)
        l_output = []
        for i in xrange(0, ncase):
            S = f.readline().strip()
            l_s = S.split()
            M = int(l_s[0]);     V = int(l_s[1]);
            C = []; L = []
            for j in xrange(0, (M-1)/2):
                S = f.readline().strip()
                l_s = S.split()
                C.append([int(l_s[0]), int(l_s[1])])
            for j in xrange((M-1)/2, M):
                S = f.readline().strip()
                L.append(int(S))

            val = self.Proc(M, V, C, L)
            num = i+1
            if(val != 1000000):
                l_output.append('Case #%(num)d: %(val)d'%locals())
            else:
                l_output.append('Case #%(num)d: IMPOSSIBLE'%locals())

        fw.write('\n'.join(l_output))
# using file set
# ----

    def Proc(self, M, V, C, L):
        ret = 1000000000;
        D = [ [1000000] * 2 for x in xrange(M+1) ]
        for i in xrange(len(L)):
            if(L[i] == 0):
                D[(M+1)/2+i][0] = 0
                D[(M+1)/2+i][1] = -1
            else:
                D[(M+1)/2+i][0] = -1
                D[(M+1)/2+i][1] = 0
        for i in xrange(len(C), 0, -1):
            if(D[i*2][0] != -1 and D[i*2+1][0] != -1):
                a00 = D[i*2][0] + D[i*2+1][0]
                o00 = D[i*2][0] + D[i*2+1][0]
            else:
                a00 = -1; o00 = -1;
            if(D[i*2][0] != -1 and D[i*2+1][1] != -1):
                a01 = D[i*2][0] + D[i*2+1][1]
                o01 = D[i*2][0] + D[i*2+1][1]
            else:
                a01 = -1; o01 = -1;
            if(D[i*2][1] != -1 and D[i*2+1][1] != -1):
                a11 = D[i*2][1] + D[i*2+1][1]
                o11 = D[i*2][1] + D[i*2+1][1]
            else:
                a11 = -1; o11 = -1;
            if(D[i*2][1] != -1 and D[i*2+1][0] != -1):
                a10 = D[i*2][1] + D[i*2+1][0]
                o10 = D[i*2][1] + D[i*2+1][0]
            else:
                a10 = -1; o10 = -1;

            if(C[i-1][0] == 1):      #and
                D[i][0] = self.update(D[i][0], a00, 0)
                D[i][0] = self.update(D[i][0], a01, 0)
                D[i][0] = self.update(D[i][0], a10, 0)
                D[i][1] = self.update(D[i][1], a11, 0)
            else:
                D[i][0] = self.update(D[i][0], o00, 0)
                D[i][1] = self.update(D[i][1], o01, 0)
                D[i][1] = self.update(D[i][1], o10, 0)
                D[i][1] = self.update(D[i][1], o11, 0)

            if(C[i-1][1] == 1):
                if(C[i-1][0] == 1):      #and
                    D[i][0] = self.update(D[i][0], o00, 1)
                    D[i][1] = self.update(D[i][1], o01, 1)
                    D[i][1] = self.update(D[i][1], o10, 1)
                    D[i][1] = self.update(D[i][1], o11, 1)
                else:
                    D[i][0] = self.update(D[i][0], a00, 1)
                    D[i][0] = self.update(D[i][0], a01, 1)
                    D[i][0] = self.update(D[i][0], a10, 1)
                    D[i][1] = self.update(D[i][1], a11, 1)

        if(V == 0):
            ret = D[1][0]
        else:
            ret = D[1][1]
##        print ret

        return ret

    def update(self, base, val, addval):
        if(val != -1 and base > val):
            base = val + addval
        return base;

if __name__ == "__main__":
    cm = BTree()
##    cm.Proc(9, 1, [[1,0],[1,1],[1,1],[0,0],],[1,0,1,0,1])
##    cm.Proc(5, 0, [[1,1],[0,0],],[1,1,0])

    cm.RunFile()
