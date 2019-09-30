def strPlusOne(in_str):
    out_str = in_str
    for ite in reversed(range(len(out_str))):
        if out_str[ite] == '0':
            out_str = out_str[:ite] + '1' + out_str[ite + 1:]
            break
        else:
            out_str = out_str[:ite] + '0' + out_str[ite + 1:]
    return out_str

def strEvalBase(in_str, base):
    ev = 0
    for ite in range(len(in_str)):
        ev *= base
        if in_str[ite] == '1':
            ev += 1
    return ev

filename = "C-large"
fin = open(filename + ".in", "r")
fout = open(filename + ".out", "w")
casenum = int(fin.readline())
for ite in range(casenum):
    # Input is always with even N.
    # Detailed description is not given here, but 1a11a1 is guaranteed to
    # be a jamcoin, with nontrivial divisor 1a1. So is 1a101a1.
    # Also, J is guaranteed to be small enough.
    # Epic trick solution incoming, no need for computation beforehand.
    in_list = fin.readline().split()
    N = int(in_list[0])
    halfN = N // 2
    if halfN * 2 < N:
        sep_str = "101"
    else:
        sep_str = "11"
    J = int(in_list[1])
    return_str = "\n"
    middle_str = (halfN - 2) * '0'
    for jte in range(J):
        return_str += "1" + middle_str + sep_str + middle_str + "1"
        for kte in range(2, 11):
            return_str += ' ' + str(strEvalBase('1' + middle_str + '1', kte))
        return_str += '\n'
        middle_str = strPlusOne(middle_str)
    fout.write("Case #{0}: {1}\n".format(ite + 1, return_str))
