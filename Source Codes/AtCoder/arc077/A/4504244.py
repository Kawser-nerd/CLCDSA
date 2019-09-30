import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n=int(input())
A=list(map(int,input().split()))
B=[]
if n%2:
    for i in range(n-1,-1,-2):
        B.append(A[i])
    for i in range(1,n-1,2):
        B.append(A[i])
else:
    for i in range(n-1,0,-2):
        B.append(A[i])
    for i in range(0,n-1,2):
        B.append(A[i])
print(*B,sep=' ')