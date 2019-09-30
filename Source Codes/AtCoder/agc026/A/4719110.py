N = int(input())
a = list(map(int,input().split()))
b_color = -1
count = 0
for i in range(N):
    if b_color == a[i]:
        count += 1
        b_color = -1
        continue
    b_color = a[i]
print(count)