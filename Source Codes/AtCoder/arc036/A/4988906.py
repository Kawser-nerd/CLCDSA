n, k = map(int, input().split())
t = [int(input()) for i in range(n)]

for i in range(2,n):
    sleep_time = t[i-2] + t[i-1] + t[i]
    if sleep_time < k:
        print(i+1)
        break
else:
    print(-1)