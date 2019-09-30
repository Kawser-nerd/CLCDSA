S = input()
p = 0
m = 0
for i in range(len(S)):
    if S[i] == '+':
        p += 1
    elif S[i] == '-':
        m += 1
l = []
for i in range(len(S)):
    if S[i] == '+':
        p -= 1
    elif S[i] == '-':
        m-= 1
    else:
        l.append(p-m)

l.sort()

ans = 0
for i in range(len(l)):
    if i <= len(l)/2-1:
        ans -= l[i]
    else:
        ans += l[i]

print(ans)