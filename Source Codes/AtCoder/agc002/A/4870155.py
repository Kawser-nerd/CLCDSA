a, b = [int(x) for x in input().split()]

if a * b <= 0:
    ans = "Zero"
elif a > 0:
    ans = "Positive"
else:
    n = b - a + 1
    ans = "Positive" if (n % 2) == 0 else "Negative"

print(ans)