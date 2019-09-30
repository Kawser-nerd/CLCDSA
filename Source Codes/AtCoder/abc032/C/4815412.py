import sys
input = sys.stdin.readline

N, K = map(int, input().split())
s = [int(input()) for _ in range(N)]

if 0 in s:
    print(N)
else:
    tmp = 1
    ans = 0
    left = right = -1

    while right < N-1:
        right += 1
        tmp *= s[right]
        if tmp > K:
            while left < right:
                left += 1
                tmp = tmp//s[left]
                if tmp <= K:
                    break
        if (right-left) > ans:
            ans = (right-left)

    print(ans)