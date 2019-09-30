x = int(input())
if x % 11 == 0:
    r = 0
elif x % 11 <= 6:
    r = 1
else:
    r = 2
ans = 2 * (x // 11) + r
print(ans)