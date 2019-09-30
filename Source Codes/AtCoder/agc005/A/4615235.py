n = input()
co = 0
su = 0
a = [n[0]]

for i in range(len(n)-1):
    if len(a) == 0:
        a.append(n[i+1])
    else:
        t = n[i+1]
        if t == "T":
            if a[-1] == "S":
                a.pop()
            else:
                a.append(t)
        else:
            a.append(t)
print(len(a))