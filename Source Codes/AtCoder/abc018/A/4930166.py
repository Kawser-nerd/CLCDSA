l = [int(input()), int(input()), int(input())]
s = sorted(l)
d = {s[2] : 1, s[1] : 2, s[0] : 3}
for i in l:
    print(d[i])