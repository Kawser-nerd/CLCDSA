s=input()
ans=""
for i in s:
    if i == "O" or i == "D":
        ans += "0"
    elif i == "I":
        ans += "1"
    elif i == "Z":
        ans += "2"
    elif i == "S":
        ans += "5"
    elif i == "B":
        ans += "8"
    else:
        ans += i
print(ans)