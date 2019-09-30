N = int(input())
a = list(map(int, input().split()))
tmp = 0
cnt = 0
if sum(a) % N != 0:
    print(-1)
    exit()

for i in range(N):
    if a[i] != sum(a) // N:
        tmp += a[i] - sum(a) // N

    if tmp != 0:
        cnt += 1

print(cnt)