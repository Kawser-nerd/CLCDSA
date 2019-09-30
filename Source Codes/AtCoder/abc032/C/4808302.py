import sys
N, K = map(int, input().split())
s = []
for i in range(N):
    s.append(int(input()))
if 0 in s:
    print(len(s))
    sys.exit()
elif K == 0:
    print(0)
    sys.exit()
else:
    left = -1
    right = 0
    mul = s[0]
    ans = 0
    while right < len(s):
        if left == right:
            right += 1
            if right == len(s):
                break
            else:
                mul = s[right]
        if mul <= K:
            ans = max(ans, right-left)
            right += 1
            if right <= len(s)-1:
                mul = mul*s[right]
            else:
                break
        elif mul > K:
            left += 1
            if left == right:
                mul = 0
            else:
                mul = mul//s[left]
print(ans)