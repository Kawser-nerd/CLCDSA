s = input()
t = input()
ans = ""
for i in range(min(len(s),len(t))):
    ans += s[i]
    ans += t[i]
if len(s) != min(len(s),len(t)):
    ans += s[-1]
elif len(t) != min(len(s),len(t)):
    ans += t[-1]

print(ans)