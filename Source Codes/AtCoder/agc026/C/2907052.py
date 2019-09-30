def run(n, s):
    '''
    ???s????????????????????
    ???????????????????????
    ?????
    '''
    sl = s[0:n]
    sr = s[n:2*n][::-1]

    dic = {}
    keys = []
    cnt = 0

    for i in range(2**n):
        red, blue, red2, blue2 = '', '', '', ''
        bits = bin(2**n+i)[3:]
        for j in range(n):
            if bits[j] == '0':
                red += sl[j]
                red2 += sr[j]
            else:
                blue += sl[j]
                blue2 += sr[j]
        keys.append(red2 + '-' + blue2)
        key = red + '-' + blue
        if key not in dic.keys():
            dic[key] = 1
        else:
            dic[key] += 1

    for key in keys:
        cnt += dic.get(key, 0)
    return cnt

    '''
    keys1 = [c[0]+'-'+c[1] for c in comb(sl)]
    keys2 = [c[0]+'-'+c[1] for c in comb(sr)]
    cnt = 0
    for key1 in keys1:
        cnt += keys2.count(key1)
    return cnt
    '''
    '''
    dict = {}
    for t0, t1 in keys:
        key = t0 + '-' + t1
        cnt = has_key(sr, t0, t1)
        if key in dict:
            dict[key] += cnt
        else:
            dict[key] = cnt
    return sum(dict.values())
    '''


'''
def comb(s):
    if len(s) == 1:
        return [(s, ''), ('', s)]
    else:
        ret = []
        for c in comb(s[0:len(s)-1]):
            ret.append((c[0]+s[-1], c[1]))
            ret.append((c[0], c[1]+s[-1]))
        return ret
'''


'''
def has_key(s, t0, t1):
    cnt = 0
    if len(s) == 1:
        if s == t0:
            return 1
        elif s == t1:
            return 1
        else:
            return 0
    else:
        a = s[0]
        if len(t0) != 0 and a == t0[0]:
            cnt += has_key(s[1:len(s)], t0[1:len(t0)], t1)
        if len(t1) != 0 and a == t1[0]:
            cnt += has_key(s[1:len(s)], t0, t1[1:len(t1)])
    return cnt
'''


def read_line():
    n = int(input())
    s = input()
    return (n, s)


def main():
    n, s = read_line()
    print(run(n, s))


if __name__ == '__main__':
    main()