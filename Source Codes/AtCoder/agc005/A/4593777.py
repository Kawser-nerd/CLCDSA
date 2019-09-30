x = input()

ans = 0
cnt_s = 0
for xx in x:
    if xx == 'T':
        if cnt_s > 0:
            cnt_s -= 1
        else:
            ans += 2
    else:
        cnt_s += 1
print(ans)