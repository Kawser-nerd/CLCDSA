n = int(input())
a = list(map(int, input().split()))
MOD = 10**9+7

if a[0] != 0:
    print(0)
    exit()

a.sort()
ans = 1
c = 0
p = 1
x = 1

for i in range(1, n):
    if a[i] == x:
        c += 1
        continue
    elif a[i] == x+1:
        ans = (ans * pow((pow(2,p,MOD)-1) ,c,MOD) * pow(2, c*(c-1)//2, MOD))%MOD
        p = c
        c = 1
        x += 1
    else:
        ans = 0
        break
else:
    ans = (ans * pow((pow(2,p,MOD)-1) ,c,MOD) * pow(2, c*(c-1)//2, MOD))%MOD

print(ans%MOD)