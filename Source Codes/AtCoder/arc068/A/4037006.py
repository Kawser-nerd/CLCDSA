x = int(input())
if not x % 11 :
    ans = x // 11 * 2
elif x % 11 <= 6 :
    ans = x // 11 * 2 + 1
else :
    ans = x // 11 * 2 + 2

print(ans)