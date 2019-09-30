a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
ans = "NO"
for i in a:
    if i in b:
        ans = "YES"
print(ans)