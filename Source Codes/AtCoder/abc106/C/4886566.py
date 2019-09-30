S = input()
K = int(input())

ans = "1"
for c in S[:K]:
    if c != "1":
        ans = c
        break
print(ans)