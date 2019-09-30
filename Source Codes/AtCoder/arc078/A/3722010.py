n = int(input())
a = list(map(int, input().split()))
total = sum(a)
count = a[0]
ans = abs(total - 2*count)
for i in range(1,n-1):
    count += a[i]
    if ans > abs(total - 2*count):
        ans = abs(total - 2*count)
print(ans)