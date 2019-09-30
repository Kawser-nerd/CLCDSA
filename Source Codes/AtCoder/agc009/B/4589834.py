import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)
#from collections import deque
N=int(input())
A=[int(input())-1 for i in range(N-1)]
A=[0]+A
table=[[] for i in range(N)]
for i in range(1,N):
    table[A[i]].append(i)
#print(table)

num=[-1]*N
def dfs(s):
    if num[s]!=-1:
        return num[s]
    child=len(table[s])
    if child==0:
        num[s]=0
        return 0
    L=[]
    n=0
    for y in table[s]:
        x=dfs(y)
        L.append(x)
    L.sort()
    for l in L:
        n=max(n+1,l+1)
    num[s]=n
    return n

dfs(0)
#print(num)
print(num[0])