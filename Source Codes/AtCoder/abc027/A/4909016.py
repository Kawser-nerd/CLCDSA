llist = list(map(int, input().split()))
cnt1 = 1
cnt2 = 0
l4 = 0

for i in range(1, 3):
    if llist[0] == llist[i]:
        cnt1 += 1
    else:
        cnt2 += 1
        l4 = llist[i]
ans = 0
if cnt1 == 1:
    ans = llist[0]
elif cnt1 == 2:
    ans = l4
else:
    ans = llist[0]

print(ans)