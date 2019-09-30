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
    if q==1: print("Yes")
    else:print("No")
    exit(0)


def ct(x,y):
    if (x>y):print("+")
    elif (x<y): print("-")
    else: print("?")

def ip():
    return int(input())

def pne(n):
    print(n,end='')

rem = pow(10,9)+7

n = ip()                                     #????1?
#n,q= (int(i) for i in input().split())       #?????2???
#a = [int(i) for i in input().split()]        #??????
#a = input()                                  #?????
#a = input().split()                          #??????
#n = ip()                      #?????(??????)(1/2)
#a=[input() for i in range(n)]    #?????(??????)(2/2)

#j???????????????
#????sum?????sum????????????
#??????
add = [0 for i in range(1000002)]
subtract = [0 for i in range(1000002)]
a = []
s =set()
for i in range(n):
    left , right = (int(i) for i in input().split())
    add[left]+=1
    subtract[right]+=1
    s.add(left)
    s.add(right)
t = "01"
c = 0
ans  = 0
l = list(s)
l.sort()
for i in range(len(l)):
    k = l[i]
    c+=add[k]
    ans = max(c,ans)
    c-=subtract[k]
print(ans)