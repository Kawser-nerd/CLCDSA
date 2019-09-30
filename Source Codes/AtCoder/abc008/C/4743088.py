n = int(input())
ans = 0
lis = [int(input()) for i in range(n)]
lis.sort()
for i in range(n):
    cou = 0
    for j in range(n):
        if i != j:
            if lis[i] % lis[j] == 0:
                cou += 1
    if cou % 2 == 1:
        ans += 0.5
    else:
        ans += (cou + 2)/(2 * cou + 2)
print(ans)