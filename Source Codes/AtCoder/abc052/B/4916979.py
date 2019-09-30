N = int(input())
S = str(input())

check = 0
ans = 0
for s in S:
    if s == "I":
        check += 1
    if s == "D":
        check -= 1
    ans = max(ans, check)
print(ans)