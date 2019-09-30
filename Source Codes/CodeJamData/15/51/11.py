#!/usr/bin/env python
import sys
sys.setrecursionlimit(10000)
from parallels import par

class ProblemX:
    def __init__(self):
        self.N, self.D = None, None
        self.S0, self.As, self.Cs, self.Rs = None, None, None, None
        self.M0, self.Am, self.Cm, self.Rm = None, None, None, None
    def read(self):
        self.N, self.D = map(int,raw_input().split())
        self.S0, self.As, self.Cs, self.Rs = map(int,raw_input().split())
        self.M0, self.Am, self.Cm, self.Rm = map(int,raw_input().split())
    def solve(self):
        self.S = [None]*self.N
        self.M = [None]*self.N
        self.MM = [None]*self.N
        self.children = []
        for i in range(self.N):
            self.children += [[]]
        self.S[0] = self.S0
        self.M[0] = self.M0
        for i in range(1,self.N):
            self.S[i] = (self.S[i-1]*self.As+self.Cs)%self.Rs
            self.M[i] = (self.M[i-1]*self.Am+self.Cm)%self.Rm
            self.MM[i] = self.M[i]%i
        for i in range(1,self.N):
            self.children[self.MM[i]] += [i]

        self.ranges = []
        for i in range(self.N):
            self.ranges.append([0]*1000)
        for i in range(1000):
            self.fillRange(0,i)
        return max(self.ranges[0])

    def fillRange(self,i,value):
        if self.S[i]<value or self.S[i]>value+self.D:
            self.ranges[i][value] = 0
        else:
            val = 1
            for c in self.children[i]:
                val += self.fillRange(c,value)
            self.ranges[i][value] = val
        return self.ranges[i][value]


if __name__ == '__main__':
#    par.par(ProblemX,1)
    par.seq(ProblemX)