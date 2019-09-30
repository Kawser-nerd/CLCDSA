n,z,w=map(int,input().split())
A=list(map(int,input().split()))
if n==1:
    print(abs(A[0]-w))
else:
    print(max(abs(A[n-1]-w),abs(A[n-2]-A[n-1])))