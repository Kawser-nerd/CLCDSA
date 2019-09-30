#!/usr/bin/python -O

import sys
from fractions import gcd
from itertools import permutations
from math import factorial

MOD = 1000000007

ncases = int(sys.stdin.readline())

def valid(s):
    seen = set()
    last = None
    for x in s:
        if x != last:
            if x in seen:
                return False
            seen.add(last)
            last = x
    return True

def isonly(c):
    guess = c[0]
    for x in c[1:]:
        if x != guess:
            return None # mixed
    return guess

for ncase in range(ncases):
    N = int(sys.stdin.readline().rstrip())
    cars = sys.stdin.readline().rstrip().split(' ')
    fail = 0
    for car in cars:
        if not valid(car):
            fail = 1
    if fail:
        # how can make valid train if one set of cars already invalid?
        print("Case #%d: %d" % (ncase+1, 0))
        continue
    isdict = {}
    isdict[None] = []
    multiplier = 1
    for car in cars:
        o = isonly(car)
        if o not in isdict.keys():
            isdict[o] = []
        isdict[o].append(car)
    # do the trivial cars
    for k in isdict.keys():
        if k:
            if len(isdict[k]) > 1:
                # must be adjacent, gives that many degrees
                multiplier *= factorial(len(isdict[k]))
                multiplier = multiplier % MOD
                # replace by one
                isdict[k] = [k]
    #print(isdict)
    # examine the non-trivial cars
    endsby = {}
    startsby = {}
    for car in isdict[None]:
        # note car[0] must be != car[-1] as non-trivial and valid
        if car[0] not in startsby.keys():
            startsby[car[0]] = []
        startsby[car[0]].append(car)
        if car[-1] not in endsby.keys():
            endsby[car[-1]] = []
        endsby[car[-1]].append(car)
    for k in startsby.keys():
        if len(startsby[k]) > 1:
            fail = 1
    for k in endsby.keys():
        if len(endsby[k]) > 1:
            fail = 1
    if fail:
        # how can make valid train if two non-trivial with same start or same
        # end?
        #print("FAIL BY NONTRIV")
        print("Case #%d: %d" % (ncase+1, 0))
        continue
    #print(startsby)
    #print(endsby)
    for k in endsby.keys():
        if k in startsby.keys():
            # must be a different car!
            car1 = endsby[k][0]
            car2 = startsby[k][0]
            # must have car1 != car2
            # must join
            endsby[k] = []
            startsby[k] = []
            # if the non-trivial
            if k not in isdict.keys():
                ncar = car1 + car2
            else:
                ncar = car1 + isdict[k][0] + car2
                isdict[k] = []
            startsby[ncar[0]] = [ncar]
            endsby[ncar[-1]] = [ncar]
    #print(startsby)
    #print(endsby)
    # ok, now all car endpoints are different
    # must connect the trivial to one endpoint if I can
    for k in isdict.keys():
        if k and len(isdict[k]) > 0:
            tcar = isdict[k][0]
            if k in endsby.keys():
                car = endsby[k][0]
                ncar = car + tcar
                endsby[k][0] = ncar
                isdict[k] = []
            elif k in startsby.keys():
                car = startsby[k][0]
                ncar = tcar + car
                startsby[k][0] = ncar
                isdict[k] = []
    #print(isdict)
    #print(startsby)
    #print(endsby)
    # so either any order is good or none are
    cars = []
    for k in isdict.keys():
        if k:
            cars += isdict[k]
    for k in startsby.keys():
        if k:
            cars += startsby[k]
    #print(cars)
    if valid(''.join(cars)):
        poss = factorial(len(cars))
        poss = poss % MOD
        poss *= multiplier
        poss = poss % MOD
    else:
        poss = 0
    print("Case #%d: %d" % (ncase+1, poss))

