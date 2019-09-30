N, M = map(int, input().split())
A = [set(map(int, input().split()[1:])) for _ in range(N)]
for a in A:
  A[0] &= a
print(len(A[0]))