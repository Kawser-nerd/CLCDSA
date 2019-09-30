def check(d):
    l = 0
    for i in d:
        if i == "o":
            l += 1
    if l == len(d):
        return True
    return False
n,r = map(int, input().split())
s = list(input())
ans = 0
p = 0
for i in range(n):
    if s[i] == ".":
        p = i
i = 0
j = 0
for _ in range(n):
    if s[j] == "o":
        j += 1
if j == n:
    print(0)
    quit()
while i < n:
    if s[i] == "o" and i < p-r+1:
        i += 1
        ans += 1
    else:
        for j in range(i,min(i+r,n)):
            s[j] = "o"
        ans += 1
    if check(s):
        break
print(ans)