a = [int(input()) for i in range(4)]

ans = 0

for i in range(a[0]+1):
    for j in range(a[1]+1):
        for k in range(a[2]+1):
            if 500*i + 100*j + 50*k == a[3]:
                ans += 1

print(ans)