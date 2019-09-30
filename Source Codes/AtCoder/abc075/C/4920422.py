# encoding:utf-8
import copy
import numpy as np
import random
import bisect #bisect_left?????????????????

N,M = map(int,input().split())

edge = []
pass_edge = []
for i in range(M):
    a,b = map(int,input().split())
    if a < b:
        a,b = b,a#??a??????
    if a==b:
        pass_edge.append([a,b])
    else:
        edge.append([a,b])

sorted_edge = sorted(edge)

bridge = {}
for i in range(1,N+1):
    bridge[i] = []

latest_bridge = [0,0]
for edge_i in sorted_edge:
    #edge = [a,b]
    if latest_bridge == edge_i:
        pass_edge.append(edge)
        pass
    else:
        latest_bridge = edge_i
        for port in range(2):
            bridge[edge_i[port]] = bridge[edge_i[port]]+[edge_i[port-1]]

# print(bridge)

def check(ie):
    a,b = ie
    used.append(a)
    copy_bridge = copy.deepcopy(bridge)
    copy_bridge[a] = list(set(copy_bridge[a])-set([b]))
    move = copy_bridge[a]
    isolate = 1
    while len(move)>0:
        pos = move.pop()
        if pos in used:
            pass
        elif pos == b:
            isolate = 0
        else:
            move = move+list(set(copy_bridge[pos]+used)-set(used))
            used.append(pos)
    return isolate

ans = 0

for ie in edge:
    # print("bi",ie)
    if ie in pass_edge:
        pass
    else:
        used = []

        ans += check(ie)
        # print(ans)

print(ans)