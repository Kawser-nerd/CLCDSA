""" AtCoder """

N, K = map(int, input().split())
s = [int(input()) for _ in range(N)]

if 0 in s:
    print(N)
    exit()

left = 0
right = 0
a = 1
ans = 0

while right < N:
    while right < N:
        if a * s[right] <= K:
            a *= s[right]
            right += 1
        else:
            break
    if left >= right:
        left += 1
        right += 1
    else:
        ans = max(ans, right - left)
        a //= s[left]
        left += 1
    

print(ans)