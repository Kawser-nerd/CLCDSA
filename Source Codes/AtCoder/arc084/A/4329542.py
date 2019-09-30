import bisect
N=int(input())
A=sorted(map(int,input().split()))
B=sorted(map(int,input().split()))
C=sorted(map(int,input().split()))
x=[1 for _ in range(N)]
ans=0
for i in range(N):
        a=bisect.bisect_left(A,B[i]) 
        c=N-bisect.bisect_right(C,B[i])
        ans+=a*c
print(ans)