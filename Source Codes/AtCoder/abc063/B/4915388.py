a=input()
b=[0]*26
for c in a:
    b[ord(c)-97] += 1
for i in b:
    if i >= 2:
        print("no")
        exit()
print("yes")