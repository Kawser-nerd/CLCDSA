#!/usr/bin/python
import sys

def other(b):
    return 'O' if b == 'B' else 'B'

def next(g,LT,bot):
    i = g
    while i < len(LT) and LT[i][0] != bot:
        i += 1
    if i < len(LT):
        return LT[i][1]
    return -1 

def solve(LT):
    i = {'O':1,'B':1}
    g = 0
    s = 0
    while g != len(LT):
        goal_bot = LT[g][0]
        new_s = abs(i[goal_bot]-LT[g][1]) + 1
        i[goal_bot] = LT[g][1]
        other_b = other(goal_bot)
        goal_other = next(g,LT,other_b) 
        if goal_other > i[other_b]:
            i[other_b] += min(new_s, goal_other - i[other_b])
        else:
            i[other_b] -= min(new_s, i[other_b] - goal_other)
        s += new_s
        g += 1
    return s

r = input()
for i in range(1,r + 1):
    line = raw_input().split(' ')
    l = int(line[0])  
    L1 = []
    L2 = []
    LT = []
    for j in range(l):
        LT.append((line[2*j+1],int(line[2*j + 2])))
    print "Case #%s: %s" % (i, solve(LT)) 
