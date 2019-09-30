S = input()
res = 0
for i in S:
    if i == "+":
        res += 1
    else:
        res -= 1
print(res)