# -*- coding: utf-8 -*-
n,m = map(int,input().split())
xy = [[0,0] for _ in range(m)]
for i in range(m):
    xy[i] = list(map(int,input().split()))

cand = []
def dfs (i,arr):
    global cand
    if i == n:
        cand.append(arr)
        return
    dfs(i + 1,arr)
    dfs(i + 1,arr + [i+1])
    return

def friend(arr):
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            if [arr[i],arr[j]] in xy or [arr[j],arr[i]] in xy or i == j:
                pass
            else:
                return False
    return True

dfs(0,[])
del cand[0]

ans = 0
for i in range(len(cand)):
    if friend(cand[i]):
        ans = max(ans,len(cand[i]))

print(ans)