#!usr/bin/env python3
from collections import defaultdict
from heapq import heappush, heappop
import sys
import math
import bisect
import itertools
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return list(sys.stdin.readline())
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
mod = 1000000007

#A
def A():
    n = I()
    c = S()
    minans = float("INF")
    maxans = 0
    for i in range(1,5):
        minans = min(minans, c.count(str(i)))
        maxans = max(maxans, c.count(str(i)))
    print(maxans, minans)

#B
def B():
    a, b = LI()
    ans = 0
    while a != b:
        if a > b:
            a = a ^ b
            b = a ^ b
            a = a ^ b
        ab = b - a
        if ab >= 8:
            a += 10
        elif ab >= 3:
            a += 5
        else:
            a += 1
        ans += 1
    print(ans)

#C
def C():
    field = SR(8)
    check = [[0] * 8 for i in range(8)]
    
    def CK(check, Point):
        Check = [[check[i][j] for j in range(8)] for i in range(8)]
        y,x = Point
        if Check[y][x] == 1:
            return False
        Check[y][x] = 1
        for i in range(8):
            if i != x and field[y][i] == "Q":
                return False
            Check[y][i] = 1
        for i in range(8):
            if i != y and field[i][x] == "Q":
                return False
            Check[i][x] = 1
        for i in range(-8, 8):
            if i != 0:
                if 0 <= y + i < 8 and 0 <= x + i < 8:
                    if field[y + i][x + i] == "Q":
                        return False
                    Check[y + i][x + i] = 1
                if 0 <= y - i < 8 and 0 <= x + i < 8:
                    if field[y - i][x + i] == "Q":
                        return False
                    Check[y - i][x + i] = 1
        return Check
    
    for i in range(8):
        for k in range(8):
            if field[i][k] == "Q":
                check = CK(check, [i, k])
                #print(check)
                if not check:
                    print("No Answer")
                    return
    ans = []
    for i in range(8):
        for k in range(8):
            if not check[i][k]:
                ans.append([i, k])
    lenans = len(ans)
    numans = []
    
    def dfs(check, num, numans):
        bnumans = numans
        for i in range(num, lenans):
            Check = CK(check, ans[i])
            if Check:
                bnumans.append(i)
                if len(bnumans) == 5:
                    for i in bnumans:
                        field[ans[i][0]][ans[i][1]] = "Q"
                    return True
                if dfs(Check, i + 1, bnumans):
                    return True
                bnumans.remove(i)
        return False
    
    if dfs(check, 0, numans):
        for a in field:
            for b in a:
                print(b, end="")
            #print()
    else:
        print("No Answer")
        
if __name__ == '__main__':
    C()