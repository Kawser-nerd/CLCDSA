flag1=False
flag2=False
s1=input()
s2=input()

win="You can win"
lose="You will lose"

for i in range(len(s1)):
    if s1[i]=="@":
        if s2[i]!="a" and s2[i]!="t" and s2[i]!="c" and s2[i]!="o" and s2[i]!="d" and s2[i]!="e" and s2[i]!="r" and s2[i]!="@":
            flag1=True
            break
    else:
        if s1[i]!=s2[i]:
            if s2[i]!="@":
                flag1=True
                break

for i in range(len(s2)):
    if s2[i]=="@":
        if s1[i]!="a" and s1[i]!="t" and s1[i]!="c" and s1[i]!="o" and s1[i]!="d" and s1[i]!="e" and s1[i]!="r" and s1[i]!="@":
            flag2=True
            break
    else:
        if s1[i]!=s2[i]:
            if s1[i]!="@":
                flag2=True
                break



if flag1 or flag2:
    print(lose)
else:
    print(win)