from statistics import mean, median,variance,stdev
import numpy as np
import sys
import math
import fractions
import itertools
import copy
from operator import itemgetter
#??????
def j(q):
    if q==1: print("YES")
    else:print("NO")
    exit(0)


def ct(x,y):
    if (x>y):print("+")
    elif (x<y): print("-")
    else: print("?")

def ip():
    return int(input())
n = ip()                                     #????1?
#a,b,c= (int(i) for i in input().split())       #?????2???
a = [int(i) for i in input().split()]        #??????
#a = input()                                  #?????
#a = input().split()                          #??????
#n = ip()                      #?????(??????)(1/2)
#a=[ip() for i in range(n)]    #?????(??????)(2/2)

#j???????????????
#????sum?????sum????????????
#??????
prev = 0
s = 0
for i in range(n):
    if a[i] == i+1:
        s+=1
        if prev:
            s-=1
            prev = 0
        else:prev = 1
    else:prev = 0
print(s)