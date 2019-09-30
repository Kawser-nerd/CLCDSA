x = input()
ans = ''
s = input()
for i in s:
    if i == x:
        continue
    ans += i
print(ans)