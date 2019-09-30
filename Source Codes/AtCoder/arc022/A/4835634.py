s="ICT"
c=0
for i in input().upper():
    if i==s[c]:
        c+=1
    if c==3:
        print("YES")
        exit()
print("NO")