import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n=int(input())
P=list(map(int,input().split()))
A,B=[],[]
for i in range(1,n+1):
    A.append(25000*i)
    B.append(25000*(n-i+1))
for i,p in enumerate(P):
    A[p-1]+=i
print(*A)
print(*B)