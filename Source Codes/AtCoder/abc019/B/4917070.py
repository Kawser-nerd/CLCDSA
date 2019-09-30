s = input()
cnt = 0
current = s[0]
ans = ""
for i in range(len(s)):
    if(s[i] == current):
        cnt += 1
    else: 
        ans+=current+str(cnt)
        cnt = 1
        current = s[i]
ans += current+str(cnt)
print(ans)