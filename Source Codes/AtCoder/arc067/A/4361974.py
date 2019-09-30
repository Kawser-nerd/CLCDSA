#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on 2019/2/
Solved on 2019/2/
@author: shinjisu
"""


# ARC 067 C Factors of Factorial
import math


def getInt(): return int(input())


def getIntList(): return [int(x) for x in input().split()]


def zeros(n): return [0]*n


def getIntLines(n): return [int(input()) for i in range(n)]


def getIntMat(n):
    mat = []
    for i in range(n):
        mat.append(getIntList())
    return mat


def zeros2(n, m): return [zeros(m)]*n


ALPHABET = [chr(i+ord('a')) for i in range(26)]
DIGIT = [chr(i+ord('0')) for i in range(10)]
N1097 = 10**9 + 7


def dmp(x, cmt=''):
    global debug
    if debug:
        if cmt != '':
            print(cmt, ':  ', end='')
        print(x)
    return x


def getDivisor(n):
    div = []
    for i in range(2, n+1):
        if n % i == 0:
            div.append(i)
    return div


# n????????? - ???????????
def getPrime(n):
    prime = [2]
    num = [i for i in range(3, n+1, 2)]
    while num != []:
        p = num.pop(0)  # ?????
        prime.append(p)
        for a in num:  # ????????????
            if a % p == 0:
                num.remove(a)
    return prime


# ???????
def getPrimeFactor(n):
    if n <= 1:
        return [1], [1]
    prime = getPrime(n)
    factor = []
    power = []
    for a in prime:
        pw = 0
        while n % a == 0:
            pw += 1
            n //= a
        if pw > 0:
            factor.append(a)
            power.append(pw)
    return factor, power


def probC():
    N = getInt()
    dmp(N)
    divisor = zeros(N+1)
    for i in range(2, N+1):
        factor, power = getPrimeFactor(i)
        dmp((factor,power), 'factor,power')
        for j in range(len(factor)):
            divisor[factor[j]] += power[j]
    dmp(divisor)
    divCount = 1
    for i in range(2, N+1):
        divCount = divCount * (divisor[i]+1) % N1097
    return divCount


debug = False  # True False
ans = probC()
print(ans)
#for row in ans:
#    print(row)


"""
def getPrimeOld(n):
    prime = [2]
    num = [i for i in range(3, n+1, 2)]
    num.reverse()
    while num != []:
        p = num.pop()  # ?????
        prime.append(p)
        for a in num:  # ????????????
            if a % p == 0:
                num.remove(a)
    return prime
"""