s = input()
l = ['O0', 'D0', 'I1', 'Z2', 'S5', 'B8']
for c in l:
    s = s.replace(c[0], c[1])
print(s)