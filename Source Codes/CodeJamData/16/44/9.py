#!/usr/bin/python3
from multiprocessing import Pool
from pprint import pprint
import sys

def check(n, strings):
    #print("in check:")
    #print(strings)
    for i in range(n):
        was = [False] * n
        was[i] = True
        cm = 0
        for j in range(n):
            if strings[i][j]=='1':
                cm += 1
                for k in range(n):
                    if strings[k][j]=='1':
                        was[k] = True
        #print(i,cm, was)
        if was.count(True)>cm:
            return False
    #print("!")
    return True
    

def find(n, strings, i, j, cost):
    if i>=n:
        if check(n, strings):
            return cost
        else:
            return n*n+1
    if j>=n:
        return find(n, strings, i+1, 0, cost)
    if strings[i][j] == '1':
        return find(n, strings, i, j+1, cost)
    res1 = find(n, strings, i, j+1, cost)
    strings[i][j] = '1'
    res2 = find(n, strings, i, j+1, cost+1)
    strings[i][j] = '0'
    return min(res1, res2)
        

def solve_test(data):
    n, strings = data
    ans = find(n, strings, 0, 0, 0)
    return ans

tests = int(input())
data = []
for test in range(tests):
    n = int(input())
    strings = []
    for i in range(n):
        strings.append(list(input()))
    data.append((n, strings))
    
with Pool(6) as p:
    res = p.map(solve_test, data)
    
for test in range(tests):
    print("Case #%d: %d" % (test+1, res[test]))
    