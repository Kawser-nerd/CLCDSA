s=input()
for i in range(len(s)//2):
    if s[i]!=s[len(s)-i-1]:
        if not (s[i]=="*" or s[len(s)-i-1]=="*"):
            print("NO")
            break
else:
    print("YES")