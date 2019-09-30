n = int(input())
a = list(map(int, input().split()))

A = []
for i, h in enumerate(a):
  A.append([h,i+1])

a_sorted = sorted(A, reverse=True)


for i in range(n):
  print(a_sorted[i][1])