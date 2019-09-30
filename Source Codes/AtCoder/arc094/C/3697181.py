def inpl(): return [int(i) for i in input().split()]
N = int(input())
A, B = [], []
for _ in range(N):
    a, b = inpl()
    A.append(a)
    B.append(b)
C = [B[i] for i in range(N) if A[i] > B[i]]
if not C:
    c = sum(A)
else:
    c = min(C)
print(sum(A)-c)