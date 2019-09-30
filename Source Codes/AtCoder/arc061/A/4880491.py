# -*- coding: utf-8 -*-

s = list(input())
n = len(s)
can = []

def dfs(i,left,sum):
    if i + 1 == n:
        sum += int("".join(s[left:]))
        can.append(sum)
        return
    dfs(i + 1,left,sum)
    dfs(i + 1,i + 1,sum + int("".join(s[left:i+1])))
    return

dfs(0,0,0)
print(sum(can))