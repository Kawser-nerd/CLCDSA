S = input().split()
res = ""
for i in S:
    if i == "Left":
        res += "< "
    elif i == "Right":
        res += "> "
    else:
        res += "A "
print(res[:-1])