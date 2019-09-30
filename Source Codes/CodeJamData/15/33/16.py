
def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret


def check(Ds, C, V):
    Ds.sort()
    for i in range(1, 1+len(Ds)):
        if i == len(Ds):
            pre_sum = C * sum(Ds)
            if pre_sum >= V:
                return 0
            else:
                return pre_sum + 1

        else:
            pre_sum = C * sum(Ds[:i])
            if pre_sum >= V:
                return 0
            if pre_sum + 1 < Ds[i]:
                return pre_sum + 1



def main():
    for t in range(1, 1+input()):
        C, D, V = read_array(int)
        Ds = read_array(int)
        if 1 not in Ds:
            Ds.append(1)
        while True:
            need = check(Ds, C, V)
            if need == 0:
                break
            else:
                Ds.append(need)


        print "Case #%d: %d" % (t, len(Ds) - D)




main()
