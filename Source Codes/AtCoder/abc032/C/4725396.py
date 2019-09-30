N, K = map(int, input().split())
lst_s = [int(input()) for _ in range(N)]
ans = 0
left = 0
mul = 1

if 0 in lst_s:
    ans = N
else:
    for right in range(N):
        mul *= lst_s[right]
        if mul <= K:
            # ????????????????
            length = right - left + 1
            ans = max(ans, length)
        else:
            # left ??????? left ??????, left ?1????
            mul //= lst_s[left]
            left += 1

print(ans)