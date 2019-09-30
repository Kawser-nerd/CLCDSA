n = int(input())
if n <= 59:
    ans = "Bad"
elif n <= 89:
    ans = "Good"
elif n <= 99:
    ans = "Great"
else:
    ans = "Perfect"
print(ans)