s=input()
d="ICT"
e=0
for i in range(len(s)):
    if e<3:
        if d[e]==str.upper(s[i]):
            e+=1
print("NO"if e!=3else"YES")