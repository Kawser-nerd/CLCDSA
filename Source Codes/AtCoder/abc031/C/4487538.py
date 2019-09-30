n = int(input())
A = [int(i) for i in input().split()]

B = -float('inf')
for i in range(n):
    C = [-float('inf'), 0, 0]
    for j in range(n):
        if i < j and C[0] < sum(A[i : j + 1][1::2]):
            C[0] = sum(A[i : j + 1][1::2])
            C[1] = i
            C[2] = j
        elif j < i and C[0] < sum(A[j : i + 1][1::2]):
            C[0] = sum(A[j : i + 1][1::2])
            C[1] = j
            C[2] = i
    B = max(B, sum(A[C[1] : C[2] + 1][0::2]))
            
print(B)