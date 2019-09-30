m = int(input())
if m < 100:
    ans = "00"
elif m <= 5000:
    if m < 1000:
        ans = "0" + str(m // 100)
    else:
        ans = int(m / 100)
elif m <= 30000:
    ans = int(m / 1000) + 50
elif m <= 70000:
    ans = ((int(m / 1000) - 30) // 5) + 80
else:
    ans = 89
print(ans)