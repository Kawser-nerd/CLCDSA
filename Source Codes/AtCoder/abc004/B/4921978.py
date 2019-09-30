c = [[0 for _ in range(4)] for _ in range(4)]
for i in range(4):
    s = input().split()
    for j in range(4):
        c[3-i][3-j] = s[j]

for x in c:
    print(' '.join(x))