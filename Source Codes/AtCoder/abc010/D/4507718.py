from collections import deque
import itertools
import numpy as np
import sys
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

N,G,E = IL()
P = IL()

friends = [IL() for i in range(E)]

edge = [[0 for i in range(N+1)] for j in range(N+1)]

for ab in friends:
    if ab[1]!=0:
        edge[ab[0]][ab[1]] = 1
    if ab[0]!=0:
        edge[ab[1]][ab[0]] = 1

for i in P:
    edge[i][N]=1

count=0
while True:
    stack = deque([0])
    used = [0]*(N+1)
    route = [None]*(N+1)
    tmp = 0
    while stack:#??
        tmp = stack.pop()
        if tmp == N:
            break
        for i in range(len(edge[tmp])):
            if edge[tmp][i] == 1 and used[i] == 0:
                stack.append(i)
                route[i] = tmp
                used[i] = 1
    else:
        break
    count += 1
    i = N
    while i != 0:#??
        j = route[i]
        edge[j][i] = 0
        i = j
print(count)