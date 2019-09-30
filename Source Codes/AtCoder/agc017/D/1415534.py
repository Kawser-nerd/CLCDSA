import sys
import random


sys.setrecursionlimit(10 ** 5 + 5)
random.seed = 1

# sys.stdin = open('d1.in')


def read_int_list():
    return list(map(int, input().split()))


def read_int():
    return int(input())


def read_str_list():
    return input().split()


def read_str():
    return input()


a = None


def dfs(root, parent):
    res = 0
    for i in a[root]:
        if i != parent:
            res ^= 1 + dfs(i, root)
    return res


def read_tree(check=False):

    if check:
        n, p = gen()
    else:
        n = read_int()
        p = [read_int_list() for i in range(n - 1)]

    global a
    a = [[] for _ in range(n)]
    for x, y in p:
        x -= 1
        y -= 1
        a[x].append(y)
        a[y].append(x)


def gen():
    n = random.randint(5, 30)

    inside = [1]
    outside = list(range(2, n + 1))
    p = []
    for i in range(n - 1):
        x = random.choice(inside)
        y = random.choice(outside)
        p.append([x, y])
        outside.remove(y)
        inside.append(y)
    return n, p


def solve():
    read_tree(check=False)
    return ['Bob', 'Alice'][dfs(0, -1) > 0]


def check():
    for i in range(1000):
        res = solve()
        print(i, res)


def main():
    # check()
    res = solve()
    print(res)


if __name__ == '__main__':
    main()