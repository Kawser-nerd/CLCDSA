n, m, c = map(int, input().split())
b = list(map(int, input().split()))
count = 0
for i in range(n):
  a = list(map(int, input().split()))
  ab = 0
  for i in range(len(a)):
    ab += a[i] * b[i]
  if ab > -c:
    count += 1
print(count)