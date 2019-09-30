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
    A1 = Input.readint()
    
    R1 = []
    for i in range(4):
        R1.append(Input.readints())
        
    A2 = Input.readint()
    
    R2 = []
    for i in range(4):
        R2.append(Input.readints())
    
    
    return set(R1[A1-1]), set(R2[A2-1])

def solve(Problem, Prep):
    R1, R2 = Problem
    
    B = R1.intersection(R2)
    
    if len(B) == 0:
        return "Volunteer cheated!"
    if len(B) == 1:
        return B.pop()
    return "Bad magician!"
        

    return 0


if __name__ == "__main__":
    doit(preprocess, readinput, solve, MultiCore = False, Verify = False, Input = SMALL, Filename = None, Problem = "A", Attempt = 0)
