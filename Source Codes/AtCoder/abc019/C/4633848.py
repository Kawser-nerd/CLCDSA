n = int(input())
a = list(map(int, input().split()))
for i in range(n):
  while a[i]%2==0:
    a[i] //= 2
print(len(set(a)))