s = list(input())
t = list(input())

x = list("atcorder@")

for i in range(len(s)):
    if s[i] == "@" and t[i] in x:
        continue
    elif t[i] == "@" and s[i] in x:
        continue
    elif s[i] == t[i]:
        continue
    else:
        print("You will lose")
        exit()
print("You can win")