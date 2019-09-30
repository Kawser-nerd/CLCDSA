#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
GC027 C
"""

n,m = map(int,input().split())
s = list(input())
ali = [0 for i in range(n)]
bli = [0 for i in range(n)]
from collections import defaultdict
graphAB = defaultdict(list)

for i in range(m):
    u,v=map(int,input().split())
    graphAB[u].append(v)
    graphAB[v].append(u)



def incrementAB(node,adj):
    if s[adj-1] == 'A':
        ali[node-1]+=1
    if s[adj-1] == 'B':
        bli[node-1]+=1

def decrementAB(node,adj):
    if s[adj-1] == 'A':
        ali[node-1]-=1
    if s[adj-1] == 'B':
        bli[node-1]-=1


def adjAB(node):
    if ali[node-1]!=0 and bli[node-1]!=0:
        return(True)
    else:
        return(False)

graphvers = set(graphAB.keys())
visitset = set()
for i in range(1,n+1):
    if not i in graphvers:
        s[i-1] = 'C'
    else:
        for j in graphAB[i]:
            incrementAB(i,j)
        if not adjAB(i):
            visitset.add(i)


while bool(visitset):
    #print(graphAB)
    #print(graphABopp)
    #print(abli)
    i = visitset.pop()
    gen = (j for j in graphAB[i] if s[j-1]!='C')
    for j in gen:
        decrementAB(j,i)
        if not adjAB(j):
            visitset.add(j)
    s[i-1] = 'C'

#print(graphAB)
#print(graphABopp)

sset= set(s)
sset.add('C')
sset.remove('C')
if bool(sset):
    print('Yes')
else:
    print('No')