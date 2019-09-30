#!/usr/bin/python

import sys

def line():
    return sys.stdin.readline()[:-1]

def readList():
    return map(eval,line().split())

modulo = 100003

chooses = dict()
def choose(n,m):
    if (n,m) not in chooses:
        if (n < m):
            chooses[(n,m)] = 0
        else:
            chooses[(n,m)] = (factorial(n) / (factorial(n-m) * factorial(m))) % modulo
    return chooses[(n,m)]

factorials = dict()
factorials[1] = 1
factorials[0] = 1
def factorial(n):
    if n not in factorials:
        i = n
        factorials[n] = 1
        while i >= 2:
            factorials[n] *= i
            i -= 1
    return factorials[n]

def buildTable(N):
    table = dict()
    for n in range(2,N+1):
        table[(n,1)] = 1
        for pos in range(2,n):
            table[(n,pos)] = sum([table[(pos,i)]*choose(n-pos-1,pos-i-1) % modulo for i in range(1,pos)]) % modulo
    return table

def ways(n,table):
    return sum([table[n,pos] for pos in range(1,n)]) % modulo
            
if __name__ == '__main__':
    numberOfCases = eval(line())
    table = buildTable(500)
    for caseNumber in range(numberOfCases):
        n = eval(line())
        answer = ways(n,table)
        print "Case #" + str(caseNumber+1) + ": " + str(answer % 100003)
