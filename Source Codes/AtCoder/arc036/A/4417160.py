n, k = map(int, input().split())
t = [0] + [int(input()) for _ in range(n)]
for i in range(3,n+1):
  if t[i] + t[i-1] + t[i-2] < k:
    print(i)
    exit()
print(-1)