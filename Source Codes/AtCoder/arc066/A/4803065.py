N = int(input())
A = [int(a) for a in input().split()]

A.sort()
B = [abs(a-b) for a,b in zip(range(N-1,-1,-1),range(N))]
B.sort()

if A==B:
    print(pow(2,N//2,10**9+7))
else:
    print(0)