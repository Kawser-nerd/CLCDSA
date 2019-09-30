a = int(input())
b = int(input())
if (a % b) == 0:
    ans = 0
else:
    ans = b - (a % b)
print(ans)