a=list(input().split())
c=""
for i in a:
    if i[0]=="A":
        c+="A"
    else:
        if i[0]!="L":
            c+=">"
        else:
            c+="<"
    c+=" "
print(c[:-1])