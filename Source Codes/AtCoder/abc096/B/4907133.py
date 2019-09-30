A = list(map(int, input().split()))

K = int(input())

for i in range(K):
  A = sorted(A)
  amax = A.pop(-1) * 2
  A.append(amax)

print(sum(A))