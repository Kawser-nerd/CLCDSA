N = int(input())
A = [int(i) for i in input().split()]
A.sort()
res = 0
for i in range(N-1):
    if A[i] == A[i+1]:
        res += 1
res = (N - res + 1) // 2 * 2 - 1
print(res)