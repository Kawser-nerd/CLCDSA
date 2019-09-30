n = int(input())
s = input()
ans = 0
for i in range(1,n-1):
    s1 = s[:i]
    s2 = s[i:]
    cnt =0 
    for x in 'abcdefghijklmnopqrstuvwxyz':
        if x in s1 and x in s2:
            cnt += 1
    ans = max(ans, cnt)
print(ans)