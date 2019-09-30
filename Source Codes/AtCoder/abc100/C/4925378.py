N = int(input())
A = list(map(int, input().split()))
count = 0
for i in range(N):
  while A[i] % 2 == 0:
    A [i] //= 2
    count += 1
print(count)