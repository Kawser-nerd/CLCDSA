import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n=int(input())
A=[int(input())-1 for _ in range(n-1)]
C=[[] for _ in range(n)]
for i,a in enumerate(A):
    C[a].append(i+1)

def depth(k):
    l=len(C[k])
    if not l:
        return 0
    else:
        D=[]
        ret=-1
        for c in C[k]:
            D.append(depth(c))
        D.sort(reverse=True)
        for i,d in enumerate(D):
            ret=max(ret,d+i+1)
        return ret

print(depth(0))