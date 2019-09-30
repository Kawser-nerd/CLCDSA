readline = open(0).readline
writelines = open(1, 'w').writelines
H, W = map(int, readline().split())
S = []; T = []
for i in range(H):
    for j, a in enumerate(readline().strip()):
        if a == "#":
            S.append("#"); T.append("#")
        else:
            if j == 0:
                S.append("#"); T.append(".")
            elif j == W-1:
                S.append("."); T.append("#")
            elif i % 2 == 0:
                S.append("#"); T.append(".")
            else:
                S.append("."); T.append("#")
    S.append("\n")
    T.append("\n")
S.append("\n")

writelines(S)
writelines(T)