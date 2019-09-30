n = int(input())
A = list(map(int, input().split()))
# print(max(A) - min(A))
min = 10**10
max = -100
for i in A:
  if (min >= i):
    min = i
  if (max <= i):
    max = i
print(max - min)