n = int(input())
a = n // 11
b = n - a * 11
if (b == 0):
    ans = a * 2
elif (b <= 6):
    ans = 1 + (a * 2)
else:
    ans = 2 + (a * 2)
print(ans)