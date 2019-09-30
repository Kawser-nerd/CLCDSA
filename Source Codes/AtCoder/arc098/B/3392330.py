n = int(input())
a = list(map(int, input().split()))

left = 0
right = 0
ans = 0
s = 0
while left < n and right < n:
    while right < n:
        if s + a[right] == s ^ a[right]:
            s += a[right]
            ans += (right - left + 1)
            right += 1
        else:
            break
    if right > left:
        s -= a[left]
        left += 1
    else:
        right += 1
        left += 1

print(ans)