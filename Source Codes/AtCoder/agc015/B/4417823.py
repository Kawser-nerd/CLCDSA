s = list(input())

ans = 0
for i in range(len(s)):
    if s[i] == 'U':
        ans += len(s)-1-i
        ans += 2*i
    else:
        ans += i
        ans += 2*(len(s)-1-i)

print(ans)