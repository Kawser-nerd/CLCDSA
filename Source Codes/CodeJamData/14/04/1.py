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
    N = Input.readint()
    
    Naomi = Input.readfloats()
    Ken = Input.readfloats()
    
    Naomi.sort(reverse = True)
    Ken.sort(reverse = True)
    
    return Naomi, Ken

def solve(Problem, Prep):
    Naomi, Ken = Problem
    
    if len(Naomi) == 1:
        if Naomi[0] > Ken[0]:
            return "1 1"
        else:
            return "0 0"
    
    N = Naomi[:]
    K = Ken[:]
    
    wins_fair = 0
    
    for i in range(len(N)):
        n = N.pop(0)
        if n < K[0]:
            K.pop(0)
            continue
        else:
            K.pop()
            wins_fair += 1

    N = Naomi[:]
    K = Ken[:]
    
    wins_unfair = 0
    
    for i in range(len(N)):
        if N[-1] < K[-1]:
            N.pop()
            K.pop(0)
        else:
            N.pop()
            K.pop()
            wins_unfair += 1
            continue
        
    return str(wins_unfair) + " " + str(wins_fair)


if __name__ == "__main__":
    doit(preprocess, readinput, solve, MultiCore = False, Verify = False, Input = LARGE, Filename = None, Problem = "D", Attempt = 0)
