
def read_array(convertor=None):
    ret = raw_input().split()
    if convertor: ret = map(convertor, ret)
    return ret

m = {}

def cal(s):
    if s in m:
        return m[s]
    if '.' not in s:
        return 0.0

    ans = 0.0
    LEN = len(s)

    for come in range(len(s)):
        pos = come
        while s[pos] != '.':
            pos = (pos + 1) % len(s)

        s2 = s[:]
        s2 = s2[:pos] + 'X' + s2[pos+1:]
        dis = pos - come
        dis = ((dis % LEN) + LEN) % LEN
        ans += LEN - dis 
        ans += cal(s2)

    ans /= len(s)
    m[s] = ans
    return ans


def main():
    T = input()
    for _ in range(T):
        s = raw_input()
        m.clear()
        ret = cal(s)

        print 'Case #%d: %.12f' % (_+1, ret)


    pass



main()
