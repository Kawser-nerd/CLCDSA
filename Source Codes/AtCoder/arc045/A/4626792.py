S=list(input().split())
a=[]
for s in S:
    if s=="Left":a.append("<")
    elif s=="Right":a.append(">")
    else:a.append("A")
print(" ".join(a))