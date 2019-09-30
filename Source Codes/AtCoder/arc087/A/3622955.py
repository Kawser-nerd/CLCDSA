n = int(input())
lis = list(map(int,input().split()))
cou = {}
for i in range(n):
    if lis[i] in cou:
        cou[lis[i]] += 1
    else:
        cou[lis[i]] = 1
ans = 0
for i in cou:
    if cou[i] < i:
        ans += cou[i]
    else:
        ans += abs(cou[i] -i)
print(ans)