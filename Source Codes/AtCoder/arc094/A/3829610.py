A, B, C = sorted(list(map(int, input().split(' '))))
ans = 0
upper = C
temp = (C-B) + (C-A)
if temp % 2 == 0:
    ans = temp // 2
else:
    temp = (C+1-B) + (C+1-(A+1))
    ans = 1 + temp // 2
print(ans)