N, K = map(int, input().split())
s_list = [int(input()) for _ in range(N)]

left = 0
right = 0
sum_num = 1
ans = 0

if 0 in s_list:
    ans = N
else:
    while left < N:
        while right < N and sum_num * s_list[right] <= K:
            sum_num *= s_list[right]
            right += 1
            
        ans = max(ans, right - left)
        if left == right:
            right += 1
        else:
            sum_num //= s_list[left]
        left += 1
print(ans)