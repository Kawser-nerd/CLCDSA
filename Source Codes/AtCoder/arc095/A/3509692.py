n = int(input())
a= list(map(int,input().split()))
b = sorted(a)
for i in range(n):
  if b[n//2] <= a[i]:
    print(b[n//2-1])
  else:
    print(b[n//2])