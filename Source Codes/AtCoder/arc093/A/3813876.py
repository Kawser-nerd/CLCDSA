N = int(input())
A = list(map(int, input().split()))
A = [0] + A + [0]
default_cost = 0
for i in range(N+1):
    default_cost += (abs(A[i+1]-A[i]))

for i in range(1, N+1):
    cost = default_cost - abs(A[i+1]-A[i]) - abs(A[i]-A[i-1]) \
        + abs(A[i+1]-A[i-1])
    print(cost)