def run(n, s):
    '''
    ???s????????????????????
    ???????????????????????
    ?????
    '''
    sl = s[0:n]
    sr = s[n:2*n][::-1]

    keys1 = [c[0]+'-'+c[1] for c in comb(sl)]
    keys2 = [c[0]+'-'+c[1] for c in comb(sr)]
    dict = {}
    for key1 in keys1:
        if key1 in dict:
            dict[key1] += 1
        else:
            dict[key1] = 1
    cnt = 0
    for key2 in keys2:
        if key2 in dict:
            cnt += dict[key2]
    return cnt


def comb(s):
    if len(s) == 1:
        return [(s, ''), ('', s)]
    else:
        ret = []
        for c in comb(s[0:len(s)-1]):
            ret.append((c[0]+s[-1], c[1]))
            ret.append((c[0], c[1]+s[-1]))
        return ret


def read_line():
    n = int(input())
    s = input()
    return (n, s)


def main():
    n, s = read_line()
    print(run(n, s))


if __name__ == '__main__':
    main()