N = int(input())
A = list(map(int,input().split()))
A.insert(0,0)
A.append(0)
cost = 0
for i in range(N+1):
    cost += abs(A[i+1]-A[i])
for i in range(1,N+1):
    if A[i-1] <= A[i] <= A[i+1] or A[i+1] <= A[i] <= A[i-1]:
        sub = 0
    elif A[i-1] <= A[i+1] <= A[i]:
        sub = 2*(A[i]-A[i+1])
    elif A[i] <= A[i-1] <= A[i+1]:
        sub = 2*(A[i-1]-A[i])
    elif A[i+1] <= A[i-1] <= A[i]:
        sub = 2*(A[i] -A[i-1])
    elif A[i] <= A[i+1]<= A[i-1]:
        sub = 2*(A[i+1]-A[i])
    print(cost - sub)