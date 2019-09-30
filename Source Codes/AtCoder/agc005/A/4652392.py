s = input()
ans = 0
cnt = 0
for a in s:
    if a == 'S':
        cnt += 1
    else:
        if cnt > 0:
            cnt -= 1
        else:
            ans += 1
print(ans+cnt)