import bisect
N=int(input())
A=list(map(int,input().split()))
A.sort()
A.append(999999999999999)
B=[]
for i in range(1,35):
    B.append(2**i)
ans=0
for i in range(N):
    if A[N-1-i]==int(A[N-1-i]):
        for j in range(len(B)):
            if A[N-1-i]<B[j]:
                break
        if A[bisect.bisect_left(A,B[j]-A[N-1-i])]==B[j]-A[N-1-i]:
            if bisect.bisect_left(A,B[j]-A[N-1-i])<N-1-i:
                A[bisect.bisect_left(A,B[j]-A[N-1-i])]-=0.1
                A[N-1-i]+=0.1
                ans+=1
print(ans)