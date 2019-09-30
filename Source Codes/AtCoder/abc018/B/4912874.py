from statistics import mean, median,variance,stdev
import numpy as np
import sys
import math
import fractions
import itertools
import copy
import collections
from operator import itemgetter
#??????
def j(q):
    if q==1: print("Yay!")
    else:print(":(")
    exit(0)


def ct(x,y):
    if (x>y):print("+")
    elif (x<y): print("-")
    else: print("?")

def ip():
    return int(input())
def printrow(a):
    for i in range(len(a)):
        print(a[i])
def combinations(n,r):
    if n<r:return 0
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))
def permutations(n,r):
    if n<r:return 0
    return math.factorial(n) // math.factorial(n - r)
#n = ip()                                     #????1?
#n,q= (int(i) for i in input().split())       #?????2???
#a = [int(i) for i in input().split()]        #??????
c = input()                                  #?????
#a = input().split()                          #??????
n = ip()                      #?????(??????)(1/2)
#a=[ip() for i in range(5)]    #?????(??????)(2/2)
#j???????????????
#????sum?????sum????????????
#??????
a = [i for i in range(len(c)+1)]
for loop in range(n):
    x,y = (int(i) for i in input().split())
    while x<y:
        temp = copy.copy(a[x])
        a[x] = copy.copy(a[y])
        a[y] = copy.copy(temp)
        x+=1
        y-=1
for i in range(1,len(c)+1):
    print(c[a[i]-1],end='')
print()