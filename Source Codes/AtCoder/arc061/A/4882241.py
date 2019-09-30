import sys
# import bisect
# import math
# import itertools
# import numpy as np
# import collections

"""Template"""


class IP:
    """
    ??????????
    """

    def __init__(self):
        self.input = sys.stdin.readline

    def I(self):
        """
        1??????????
        :return: int
        """
        return int(self.input())

    def S(self):
        """
        1?????(str
        :return: str
        """
        return self.input()

    def IL(self):
        """
        1???????????????(int
        :return: ???
        """
        return list(map(int, self.input().split()))

    def SL(self):
        """
        1???????????????????
        :return: ???
        """
        return list(map(str, self.input().split()))

    def ILS(self, n):
        """
        1????????(int
        :param n: ??
        :return: ???
        """
        return [int(self.input()) for _ in range(n)]

    def SLS(self, n):
        """
        1?????????str
        :param n: ??
        :return: ???
        """
        return [self.input() for _ in range(n)]

    def SILS(self, n):
        """
        Some Int LineS
        ??????????
        :param n: ??
        :return: list
        """
        return [self.IL() for _ in range(n)]

    def SSLS(self, n):
        """
        Some String LineS
        :param n: ??
        :return: list
        """
        return [self.SL() for _ in range(n)]


class Idea:
    def __init__(self):
        pass

    def HF(self, p):
        """
        Half enumeration
        ???????
        p?????????????????
        ????????????
        :param p: list : ???????
        :return: list : ?????????????
        """
        return sorted(set(p[i] + p[j] for i in range(len(p)) for j in range(i, len(p))))

    def Bfs2(self, a):
        """
        bit_full_search2
        bit???????
        ???????2???????10?????????
        :return: list?? : ??? 2??(16?)  2?? 10??
        """
        # ??
        # https://blog.rossywhite.com/2018/08/06/bit-search/
        # https://atcoder.jp/contests/abc105/submissions/4088632
        value = []
        for i in range(1 << len(a)):
            output = []

            for j in range(len(a)):
                if self.bit_o(i, j):
                    """???j+1???i?1??????"""
                    # output.append(a[j])
                    output.append(a[j])
            value.append([format(i, 'b').zfill(16), sum(output)])

        value.sort(key=lambda x: x[1])
        bin = [value[k][0] for k in range(len(value))]
        val = [value[k][1] for k in range(len(value))]
        return bin, val

    def S(self, s, r=0, m=-1):
        """
        ????????????????????
        :param s: ???????
        :param r: revers?????? 0=False 1=True
        :param m: ?2??????????????????????
        :return: None
        """
        r = bool(r)
        if m == -1:
            s.sort(reverse=r)
        else:
            s.sort(reverse=r, key=lambda x: x[m])

    def bit_n(self, a, b):
        """
        bit????????0??????True????
        ??????n
        :param a: int
        :param b: int
        :return: bool
        """
        return bool((a >> b & 1) > 0)

    def bit_o(self, a, b):
        """
        bit????????1????True???
        one?1
        :param a: int
        :param b: int
        :return: bool
        """
        return bool(((a >> b) & 1) == 1)

    def ceil(self, x, y):
        """
        Round up
        ??????????
        :param x: int
        :param y: int
        :return: int
        """
        return -(-x // y)

    def ave(self, a):
        """
        ???????
        :param a: list
        :return: int
        """
        return sum(a) / len(a)

    def gcd(self, x, y):
        if y == 0:
            return x
        else:
            return self.gcd(y, x % y)


"""??????????"""


def main():
    # 1?????
    r, e, p = range, enumerate, print
    ip = IP()
    id = Idea()
    mod = 10 ** 9 + 7

    """?????????"""
    s = str(ip.I())
    ans = 0
    for i in r(1 << len(s) - 1):
        output = 0
        res = 0
        for j in r(len(s) - 1):
            if (i >> j) & 1:
                output += int(s[res:j + 1])
                res = j + 1
        output += int(s[res:len(s)])
        ans += output
    p(ans)


main()