N = int(input())
a = list(map(int, input().split()))
k = 0
cnt = 0
while (k <= N - 2):
  if (a[k] == a[k+1]):
    cnt += 1
    k += 2
  else:
    k += 1
print(cnt)