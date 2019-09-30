s = input()
t = input()
for i in range(len(s)):
    if s[i]!=t[i]:
        if ( s[i]=="@" and t[i] in "atcoder") or (t[i]=="@" and s[i] in "atcoder") or (s[i]=="@" and t[i]=="@"):
            continue
        else:
            print("You will lose")
            exit()
else:
    print("You can win")