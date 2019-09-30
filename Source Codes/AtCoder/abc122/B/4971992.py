s = input()
t = [-1]

for i in range(len(s)):
    if s[i] != "A" and s[i] != "G" and s[i] != "C" and s[i] != "T":
        t.append(i)
t.append(len(s))

ans = 0
for j in range(len(t) - 1):
    x = t[j+1] - t[j] - 1
    if x > ans:
        ans = x

print(ans)