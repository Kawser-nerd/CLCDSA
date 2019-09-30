filename = "B-large"
fin = open(filename + ".in", "r")
fout = open(filename + ".out", "w")
casenum = int(fin.readline())
for ite in range(casenum):
    in_str = fin.readline()
    if in_str[-1] == '\n':
        in_str = in_str[:-1]
    in_str = in_str + '+'
    count = 0
    for jte in range(len(in_str) - 1):
        if in_str[jte] != in_str[jte + 1]:
            count += 1
    return_str = str(count)
    fout.write("Case #{0}: {1}\n".format(ite + 1, return_str))
