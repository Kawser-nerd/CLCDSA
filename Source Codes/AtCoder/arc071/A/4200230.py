#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb  9 11:04:32 2019

@author: shinjisu
"""


# arc 071 dubious document
def getInt(): return int(input())


def zeros(n): return [0]*n


def db(x):
    global debug
    if debug:
        print(x)


debug = False
n = getInt()
Str = zeros(n)
for i in range(n):
    Str[i] = [c for c in input()]
    Str[i].sort()
    Str[i] = ''.join(Str[i])
db((Str, n))
idx = zeros(n)
widx = zeros(n)
dub = ''
for i in range(len(Str[0])):
    allFound = True
    for j in range(1, n):  # ?????
        widx[j] = Str[j].find(Str[0][i], idx[j])
        if widx[j] == -1:
            allFound = False
    if allFound:
        dub = dub + Str[0][i]
        db(dub)
        for j in range(1, n):
            idx[j] = widx[j]+1
print(dub)