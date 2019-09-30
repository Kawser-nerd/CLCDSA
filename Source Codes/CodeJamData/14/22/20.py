from functools import *

inf = open('B-large.in')
ouf = open('output.txt', 'w')
input = lambda: inf.readline().strip()
print = partial(print, file = ouf)


def gen_nums(x):
    nums = []
    x_len = len(x)
    for i, c in enumerate(x):
        if c == '1':
            nums.append(x[:i] + '0' + '?' * (x_len - i - 1))
    return nums


def get_ways(a, b, k):
    n = len(a)
    res = 1
    for i in range(n):
        if k[i] == '?':
            if a[i] == '?':
                res *= 2
            if b[i] == '?':
                res *= 2
        else:
            kc = int(k[i])
            a_vars = [int(a[i])] if a[i] != '?' else [0, 1]
            b_vars = [int(b[i])] if b[i] != '?' else [0, 1]
            tr = 0
            for ac in a_vars:
                for bc in b_vars:
                    tr += (ac & bc == kc)
            res *= tr
    return res


def solve():
    a, b, k = map(lambda s: bin(int(s))[2:], input().split())
    len_max = max(len(a), len(b), len(k))
    a = '0' * (len_max - len(a)) + a
    b = '0' * (len_max - len(b)) + b
    k = '0' * (len_max - len(k)) + k
    a_nums = gen_nums(a)
    b_nums = gen_nums(b)
    k_nums = gen_nums(k)
    res = 0
    for mask_a in a_nums:
        for mask_b in b_nums:
            for mask_k in k_nums:
                res += get_ways(mask_a, mask_b, mask_k)
    print(res)
    
    
tests = int(input())
for z in range(tests):
    print("Case #{}: ".format(z + 1), end = '')
    solve()

ouf.close()