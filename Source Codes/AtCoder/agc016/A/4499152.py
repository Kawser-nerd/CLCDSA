s = input()
m = set(s)

if len(m) == 1:
    print(0)
    exit()

ans = float('inf')
for k in m:
    cnt = 0
    tt = s
    while True:
        cnt += 1
        t = ''
        for i in range(len(tt)-1):
            if tt[i] == k or tt[i+1] == k:
                t += k
            else:
                t += tt[i+1]
        tt = t

        if len(set(tt)) == 1:
            break
    ans = min(ans,cnt)       
print(ans)