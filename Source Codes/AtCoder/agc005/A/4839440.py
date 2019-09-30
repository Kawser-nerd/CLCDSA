X = input()
t = 0
s = 0
for i in X:
    if i == 'T':
        if s > 0:
            s -= 1
        else:
            t += 1
    if i == 'S':
        s += 1
print(s + t)