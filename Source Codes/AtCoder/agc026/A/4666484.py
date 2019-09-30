N = int(input())
a = list(map(int, input().split()))
color = 0
num = 1
count = 0
for i in range(N):
    if a[i] == color:
        num += 1
    else:
        color = a[i]
        if num >= 2:
            count += num // 2
            num = 1
    if i == N - 1:
        if num >= 2:
            count += num // 2
print(count)