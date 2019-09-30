#!/usr/local/bin/python3

import bisect
import sys

(a, b) = tuple(map(int, input().split(' ')))

if a <= b:
    print("Impossible")
    sys.exit()

n = a + b

def ask(i, j):
    print("? ", i, j)
    ans = input()
    if ans == 'Y':
        return True
    elif ans == 'N':
        return False

path = []
nlen = b + 1
for i in range(n):
    if len(path) == 0:
        path.append(i)
        if len(path) >= nlen:
            break
    else:
        if ask(path[-1], i):
            path.append(i)
            if len(path) >= nlen:
                break
        else:
            path.pop()
            nlen -= 1
    #print(path, nlen)
            
o1 = path[-1]

result = ''
for i in range(n):
    if i != o1:
        if ask(o1, i):
            result += '1'
        else:
            result += '0'            
    else:
        result += '1'        

print('!', result)