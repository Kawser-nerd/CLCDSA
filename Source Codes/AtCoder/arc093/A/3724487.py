def inpl(): return [int(i) for i in input().split()]
N = int(input())
A = [0]+inpl()+[0]
sumtr = 0
for i in range(N+1):
    sumtr += abs(A[i+1]-A[i])
for i in range(1,N+1):
    print(sumtr +abs(A[i+1]-A[i-1]) -abs(A[i]-A[i-1]) -abs(A[i+1]-A[i]))