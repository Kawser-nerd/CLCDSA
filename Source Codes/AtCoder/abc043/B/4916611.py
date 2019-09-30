S = list(input())
ans = []
for i in S:
    if (i == "0"):
        ans.append("0")
    elif (i == "1"):
        ans.append("1")
    else:
        if (len(ans) != 0):
            del ans[-1]
print("".join(ans))