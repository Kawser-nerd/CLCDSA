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
h,w= (int(i) for i in input().split())       #?????2???
#a = [int(i) for i in input().split()]        #??????
#a = input()                                  #?????
#a = input().split()                          #??????
#n = ip()                      #?????(??????)(1/2)
#a=[ip() for i in range(n)]    #?????(??????)(2/2)

#j???????????????
#????sum?????sum????????????
#??????
n = ip()
a = [int(i) for i in input().split()]
horz = 1
vert = 1
x = 0
y = 0
ans  = [[0 for i in range(w)] for i in range(h)]
pos = 0
for i in range(h*w):
    ans[y][x] = pos+1
    a[pos]-=1
    if a[pos] ==0:
        pos+=1
    if y == h-1 and vert == 1:
        x+=1
        vert = -1
    elif y == 0 and vert == -1:
        x+=1
        vert = 1
    else: y+=vert
for i in range(h):
    for k in range(w):
        if k+1 != w: print(ans[i][k],"",end="")
        else : print(ans[i][k],end="")
    print()