import collections
import itertools
import numpy as np
import sys
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

s = S()

abc = "abcdefghijklmnopqrstuvwxyz"
num = [i for i in range(26)]
dic = {"null":-1}
for i in range(26):
    dic[abc[i]] = num[i]+1

l = []
tmp = "null"
if len(s) == 26:
    for i in range(25,-1,-1):
        if dic[tmp] < dic[s[i]]:
            tmp = s[i]
            l.append(s[i])
        else:
            for j in l:
                if dic[j] < dic[s[i]]:
                    continue
                else:
                    print(s[:i]+j)
                    exit()
                    break
    else:
        print(-1)
else:
    for i in range(26):
        if abc[i] in s:
            continue
        else:
            print(s+abc[i])
            break