filename = "D-large"
fin = open(filename + ".in", "r")
fout = open(filename + ".out", "w")
casenum = int(fin.readline())
for ite in range(casenum):
    in_list = fin.readline().split()
    K = int(in_list[0])
    C = int(in_list[1])
    S = int(in_list[2])
    Smin = (K - 1) // C + 1 # == ceil(K/C).
    '''if S >= K:
        return_str = ""
        for jte in range(K):
            return_str += ' ' + str(jte + 1)
        return_str = return_str[1:]
        # As with the small solution.
        # Guarantee something at least!
    el'''
    if S < (K - 1) // C + 1:
        return_str = "IMPOSSIBLE"
        # Looking into each tile can and can only determine C tiles in the
        # original.
        # I spent awfully long getting this point.
    else:
        # In base K, choose numbers 01...C-1, CC+1... etc.
        # For the last one, choose ...K-1, in order not to exceed limit.
        # Note the limit excession the other way, too.
        # Note that index starts at 1, so adding 1 is necessary.
        return_str = ''
        for jte in range(Smin - 1):
            next_num = 0
            for kte in range(C):
                next_num *= K
                next_num += kte + C * jte
            return_str += str(next_num + 1) + ' '
        next_num = 0
        for kte in range(K - C, K):
            next_num *= K
            if kte >= 0:
                next_num += kte
        return_str += str(next_num + 1)
    fout.write("Case #{0}: {1}\n".format(ite + 1, return_str))
