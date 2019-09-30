N = int(input())
Sss = [input() for _ in range(N)]
Sss_tr = list(map(''.join, zip(*Sss))) # ??

ans = 0
for k in range(N):
    for i in range(N):
        if (Sss[i][-k:] + Sss[i][:-k]) != Sss_tr[i - k]:
            break
    else:
        ans += N

print(ans)