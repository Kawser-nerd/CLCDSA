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
n = ip()                                     #????1?
#n,q= (int(i) for i in input().split())       #?????2???
#a = [int(i) for i in input().split()]        #??????
#b = input()                                  #?????
#a = input().split()                          #??????
#n = ip()                      #?????(??????)(1/2)
#a=[ip() for i in range(5)]    #?????(??????)(2/2)
#j???????????????
#????sum?????sum????????????
#??????
u = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,51,53,59,61,67,71,73,79,83,89,97]

factor = [0 for i in range(100)]
for i in range(2,n+1):
    sn = i
    p = 1
    while p<100:
        p+=1
        if p==100:break
        if sn%p == 0:
            factor[p]+=1
            sn//=p
            p=1
use = [factor[i] for i in range(100) if i in u and factor[i]]
#print([i for i in range(100)])
#print(factor)
#print(use)
ov74 = 0
ov4 = 0
ov14 = 0
ov24 = 0
ov2 = 0
ov4u13 = 0
ov2u3 = 0
ov2u23 = 0
for i in range(len(use)):
    if use[i] >=74:ov74+=1
    if use[i] >= 4:ov4+=1
    if use[i] >=14:ov14+=1
    if use[i] >=24:ov24+=1
    if use[i] == 2 or use[i]==3:ov2u3+=1
    if 14>use[i] and use[i]>=4: ov4u13+=1
    if 24>use[i] and use[i]>=2: ov2u23+=1
q = ov74
w = combinations(ov4,2) * ov2u3 + 3*combinations(ov4,3)
e = ov14 * ov4u13 + permutations(ov14,2)
r = ov24 * ov2u23 + permutations(ov24,2)
print(q+w+e+r)