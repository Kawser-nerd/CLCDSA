import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
n=int(input())
A=list(map(int,input().split()))
a,b=max(A),min(A)
if a-b>1:
    print('No')
elif a==b:
    print('Yes' if a<=n//2 or a==n-1 else 'No')
else:
    c=A.count(b)
    print('Yes' if 1<=a-c<=(n-c)//2 else 'No')