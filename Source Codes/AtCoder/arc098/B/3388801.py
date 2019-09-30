n = int(input())
a = list(map(int,input().split()))

ans = 1
left = 0

now = a[0]
for right in range(1,n):
    while True:
        if now & a[right] == 0:
            now = now | a[right]
            ans += right - left +1
            break
        else:
            now = now^a[left]
            left += 1
print(ans)