from copy import deepcopy
N, x = map(int, input().split())
A = [int(a) for a in input().split()]

minA = deepcopy(A)
Ans = sum(minA) #??????????
for i in range(1, N): #i???????
    for j in range(N):
        minA[j] = min(minA[j], A[j-i])
    Ans = min(Ans, x * i + sum(minA))
print(Ans)