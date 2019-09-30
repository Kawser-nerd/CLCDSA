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
#n = ip()                                     #????1?
#a,b,c= (int(i) for i in input().split())       #?????2???
a = [int(i) for i in input().split()]        #??????
#a = input()                                  #?????
#a = input().split()                          #??????
#n = ip()                      #?????(??????)(1/2)
#a=[ip() for i in range(n)]    #?????(??????)(2/2)

#j???????????????
#????sum?????sum????????????
#??????
a.pop(6)
a.pop(5)
a.pop(2)
s = sum(a)
for i in range(4):
    if i != 1 and a[i]%2: s-=1
if s+3==sum(a):s = sum(a)
if s+2==sum(a) and a[0] and a[2] and a[3] > 3:s = sum(a)-1
print(s)