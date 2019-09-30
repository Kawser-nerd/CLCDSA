def replace(s: list, a):
    s = list(s)
    i = s.index(a)
    s[0], s[i] = s[i], s[0]
    return s


def adopt(s: list, s0: list):
    res = [0] * len(s)

    for i in range(len(s)):
        if s0[i] in s:
            res[i] = s0[i]
            s[s.index(s0[i])] = 0
    import collections
    rest = collections.deque([c for c in s if c != 0])
    for i in range(0, len(res)):
        if res[i] == 0:
            res[i] = rest.pop()
    return res


def main():
    # print(adopt(list("toder"), list("coder")))
    # return

    N, K = map(int, input().split())
    s = list(input())
    s0 = list(s)

    for pos in range(len(s)):
        pq = sorted(s[pos:])
        for a in pq:
            t = replace(s[pos:], a)[1:]
            t = adopt(t, s0[pos+1:])
            ss = s[:pos] + [a] + t
            kk = sum([ss[i]!=s0[i] for i in range(len(ss))])
            if kk > K:
                continue
            if len(t) != 0:
                s = ss
                break
    print("".join(s))


if __name__ == '__main__':
    main()