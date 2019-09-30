day = str(input())[0:3]
if day == "Mon":
    ans = 5
elif day == "Tue":
    ans = 4
elif day == "Wed":
    ans = 3
elif day == "Thu":
    ans = 2
elif day == "Fri":
    ans = 1
else:
    ans = 0
print(ans)