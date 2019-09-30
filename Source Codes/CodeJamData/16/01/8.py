filename = "A-large"
fin = open(filename + ".in", "r")
fout = open(filename + ".out", "w")
casenum = int(fin.readline())
for ite in range(casenum):
    num_count = int(fin.readline())
    fulllist = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    currlist = []
    total_num = 0
    if num_count == 0:
        return_str = 'INSOMNIA'
    else:
        while len(currlist) < len(fulllist):
            total_num += num_count
            numstr = str(total_num)
            for s in numstr:
                if s not in currlist:
                    currlist.append(s)
        return_str = numstr
    fout.write("Case #{0}: {1}\n".format(ite + 1, return_str))
