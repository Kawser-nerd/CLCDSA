l1, l2, l3 = map(int, input().split())

if l1==l2:
    ans = l3
if l2==l3:
    ans = l1
if l3==l1:
    ans = l2

print(ans)