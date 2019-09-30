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
    C, F, X = Input.readfloats()
    
    return C, F, X

def solve(Problem, Prep):
    C, F, X = Problem
    
    S = 2.0
    Farms = 0.0
    Time = 0.0
    cookies = 0.0
    
    while True:
        timeToNewFarm = C / S
        timeToFinish = X / S
        if timeToFinish < timeToNewFarm:
            return "%.7f"%(Time + timeToFinish)
        
        timeDiff = timeToFinish - timeToNewFarm
        if timeDiff * F < C:
            return "%.7f"%(Time + timeToFinish)
        Time += timeToNewFarm
        S += F

    return 0


if __name__ == "__main__":
    doit(preprocess, readinput, solve, MultiCore = True, Verify = False, Input = LARGE, Filename = None, Problem = "B", Attempt = 0)
