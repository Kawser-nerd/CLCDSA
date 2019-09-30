n = int(input())
a = list(map(int, input().split()))

a.insert(0, 0)
a.append(0)

total_tmp = 0
for i in range(1, n+2):
    total_tmp += abs(a[i] - a[i-1])

for i in range(1, n+1):
    # delete the i-th spot
    total = total_tmp - abs(a[i] - a[i-1]) - abs(a[i+1] - a[i]) + abs(a[i+1] - a[i-1])
    print(total)