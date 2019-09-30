a,b = map(int,input().split())
s = input()
if s[a] != '-':
    print("No")
else:
    found = True
    for i in range(len(s)):
        if i != a and not s[i].isdigit():
            found = False
    if found:
        print("Yes")
    else:
        print("No")