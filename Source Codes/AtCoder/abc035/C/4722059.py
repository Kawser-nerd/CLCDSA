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

#n = ip()                                     #????1?
n,q= (int(i) for i in input().split())       #?????2???
#a = [int(i) for i in input().split()]        #??????
#a = input()                                  #?????
#a = input().split()                          #??????
#n = ip()                      #?????(??????)(1/2)
#a=[input() for i in range(n)]    #?????(??????)(2/2)

#j???????????????
#????sum?????sum????????????
#??????
add = [0 for i in range(n+1)]
subtract = [0 for i in range(n+1)]
a = []

for i in range(q):
    left , right = (int(i) for i in input().split())
    add[left]+=1
    subtract[right]+=1
t = "01"
c = 0
for i in range(1,n+1):
    c+=add[i]
    print(t[c%2],end='')
    c-=subtract[i]
print()