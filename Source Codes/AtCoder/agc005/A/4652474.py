s = input()
t = []
for a in s:
    t.append(a)
    if len(t) >= 2:
        if t[-2] == 'S' and t[-1] == 'T':
            for i in range(2):
                t.pop(-1)
print(len(t))