#3
s = input()
t = input()
ans = True

for i in range(len(s)):
    if s[i]=='@':
        if t[i] not in "atcoder@":
            ans = False
            break
    elif t[i]!='@':
        if s[i] != t[i]:
            ans = False
            break
            
for i in range(len(t)):
    if t[i]=='@':
        if s[i] not in "atcoder@":
            ans = False
            break
    elif s[i] != '@':
        if s[i] != t[i]:
            ans = False
            break

if ans:
    print("You can win")
else:
    print("You will lose")