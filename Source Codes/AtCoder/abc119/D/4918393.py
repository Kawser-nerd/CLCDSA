# coding: utf-8
# Your code here!

import bisect

A, B, Q = map(int, input().rstrip().split(' '))

X = [-int(1e12)] + sorted([int(input()) for _ in range(A)]) + [int(1e12)]
Y = [-int(1e12)] + sorted([int(input()) for _ in range(B)]) + [int(1e12)]

i = 1
j = 1
pos = []
near = []
if X[1] > Y[1]:
    pos.append(Y[1])
    near.append(X[1] - Y[1])
    j = 2
else:
    pos.append(X[1])
    near.append(Y[1] - X[1])
    i = 2
while True:
    if X[i] > Y[j]:
        pos.append(Y[j])
        near.append(min(X[i] - Y[j], Y[j] - X[i-1]))
        j += 1
    else:
        pos.append(X[i])
        near.append(min(Y[j] - X[i], X[i] - Y[j-1]))
        i += 1
        
    if i >= (A + 1) and j >= (B + 1):
        break

pos = [-int(1e12)] + pos + [int(1e12)]
near = [int(1e12)] + near + [int(1e12)]
    
for _ in range(Q):
    x = int(input())
    insert_index = bisect.bisect_left(pos, x)
    if pos[insert_index] - x + near[insert_index] > x - pos[insert_index-1] + near[insert_index-1]:
        print(x - pos[insert_index-1] + near[insert_index-1])
    else:
        print(pos[insert_index] - x + near[insert_index])