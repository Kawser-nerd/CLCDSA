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
#a,b,c= (int(i) for i in input().split())       #?????2???
#a = [int(i) for i in input().split()]        #??????
#a = input()                                  #?????
#a = input().split()                          #??????
#n = ip()                      #?????(??????)(1/2)
#a=[input() for i in range(n)]    #?????(???????)(2/2)
#a=[ip() for i in range(n)]    #?????(??????)(2/2)

#j???????????????
#????sum?????sum????????????
#??????
cityname = []
population = []
for i in range(n):
    x,y = input().split()
    cityname.append(x)
    population.append(int(y))
if max(population) / sum(population) > 0.5:
    a = population.index(max(population))
    print(cityname[a])
else :
    print("atcoder")