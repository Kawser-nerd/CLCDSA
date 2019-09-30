x = input()
t = x.replace("ch","X")
for i in t:
    if i=="X" or i=="o" or i=="k" or i=="u":
        continue
    else:
        print("NO")
        exit()
else:
    print("YES")