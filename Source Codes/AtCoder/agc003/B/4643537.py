n = int(input())
a = [int(input()) for _ in range(n)]
cnt = 0
for i in range(n):
    if i != n-1 and a[i] % 2 == 1:
        if a[i+1] != 0:
            a[i+1] -= 1
            cnt += 1
    cnt += a[i]//2
print(cnt)