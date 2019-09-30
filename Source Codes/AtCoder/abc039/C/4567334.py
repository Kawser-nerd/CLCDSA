# -*- coding: utf-8 -*-
"""
Created on Tue Feb 12 15:50:41 2019

@author: shinjisu
"""

#import numpy as np
#import math
def getInt(): return int(input())
def getIntList(): return [int(x) for x in input().split()]
def getIntListArr(): return np.array(input().split(), dtype=np.longlong)
def getIntListArr(): return np.array(getIntList(), dtype=np.longlong)

def zeros(n): return [0]*n
def zeros2(n, m): return [zeros(m)]*n # obsoleted zeros((n, m))???
def zerosArr(n): return np.zeros(n, dtype=np.longlong)

def getIntLines(n): return [int(input()) for i in range(n)]
def getIntLinesArr(n):
    data = zerosArr(n)
    for i in range(n):
        data[i] = getInt()
    return data

def getIntMat(n, m):  # n??????1??m????
    mat = zeros2(n, m)
    for i in range(n):
        mat[i] = getIntList()
    return mat
def getIntMatArr(n, m):  # n??????1??m????
    mat = zerosArr((n, m))
    for i in range(n):
        mat[i] = getIntList()
    return mat


ALPHABET = [chr(i+ord('a')) for i in range(26)]
DIGIT = [chr(i+ord('0')) for i in range(10)]
N1097 = 10**9 + 7
INF = 10**18


def dmp(x, cmt=''):
    global debug
    if debug:
        if cmt != '':
            print(cmt, ':  ', end='')
        print(x)
    return x


class Debug():
    def __init__(self):
        self.debug = True

    def off(self):
        self.debug = False

    def dmp(self, x, cmt=''):
        if self.debug:
            if cmt != '':
                print(cmt, ':  ', end='')
            print(x)
        return x


def prob_B():
    d = Debug()
    d.off()
    S = input()
    scale = ['Do', '#', 'Re', '#', 'Mi', 'Fa', '#', 'So', '#', 'La', '#', 'Si']
    d.dmp((S))
    for i in range(len(S)):
        if  S[i] == 'W' and S[i+1] == 'W':
            break
    if S[(i+6) % 20] == 'W':
        do = (i+1) % 20
    else:
        do = (i+8) % 20
    return scale[(-do+len(scale)) % len(scale)]


print(prob_B())
#ans = prob_B()
#for e in ans:
#    print(e[1])