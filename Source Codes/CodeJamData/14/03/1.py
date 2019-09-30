import sys # standard Python library
import itertools # standard Python library
#from PerfectAllocation import PerfectAllocation # http://pastebin.com/5sv1quf0
from operator import itemgetter # standard Python library
import bisect # standard Python library
import math # standard Python library
import copy # standard Python library
from fractions import gcd # standard Python library
from utilities import *  # this is helper file which can be found at http://pastebin.com/RNbC6TtE. It does not contain problem-specific algorithms.


sys.setrecursionlimit(1000) #1000 is default
Prep = []


def preprocess():
    return None
    
def readinput(Input):
    R, C, M = Input.readints()
    
    return R, C, M


def solve(Problem, Prep):
    memoize = set()
    
    def recourse(R, C, Matrix, M):
        if (R, C, M) in memoize:
            return False
        
        if M == 0:
            return True
        if R >= 2 and C > 2 and M >= R:
            if recourse(R, C-1, Matrix, M - R):
                x = C - 1
                for y in range(R):
                    Matrix[y][x] = "*"
                return True
        if R > 2 and C >= 2 and M >= C:
            if recourse(R - 1, C, Matrix, M - C):
                y = R - 1
                for x in range(C):
                    Matrix[y][x] = "*"
                return True
        if R == 2 and C == 2 and M == 3:
            Matrix[0][1] = "*"
            Matrix[1][0] = "*"
            Matrix[1][1] = "*"
            return True
        if R == 2 or C == 2:
            return False
        
        AllocateR = min(M, R - 2)
        M2 = M - AllocateR
        AllocateC = min(M2, C - 3)
        if AllocateC + AllocateR == M:
            x = C - 1
            for y in range(R - AllocateR, R):
                Matrix[y][x] = "*"
            y = R - 1
            for x in range(C - AllocateC - 1, C):
                Matrix[y][x] = "*"
            return True
        
        memoize.add((R, C, M))
        return False
        
        
    R, C, M = Problem
    
    if R == 1:
        return "\n" + "*" * M + "." * (C - M - 1) + "c" 

    if C == 1:
        return "\n" + "*\n" * M + ".\n" * (R - M - 1) + "c" 
    
    Matrix = [["."] * C for _ in range(R)]
    Matrix[0][0] = "c"
    
    Answer = recourse(R, C, Matrix, M)
    
    if Answer == False:
        return "\nImpossible"
    
    Answer = "\n" + "\n".join(["".join(Ma) for Ma in Matrix])
    
    assert Answer.count("*") == M

    return Answer


if __name__ == "__main__":
    doit(preprocess, readinput, solve, MultiCore = False, Verify = False, Input = LARGE, Filename = None, Problem = "C", Attempt = 3)
