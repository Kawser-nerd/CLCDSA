N, x = map(int, input().split())
A = list(map(int, input().split()))

total = 0
for i in range(1, len(A)):
    diff = A[i-1] + A[i] -x
    if diff <= 0:
        continue
    if diff <= A[i]:
        A[i] -= diff
    else:
        A[i-1] -= diff - A[i]
        A[i] = 0
    total += diff

print(total)