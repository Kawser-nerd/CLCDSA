# https://beta.atcoder.jp/contests/arc079/tasks/arc079_a


def solve():
    from_start = set()
    to_end = set()
    n, m = map(int, input().split())

    for _ in range(m):
        a, b = map(int, input().split())
        if a == 1:
            from_start.add(b)
        elif b == n:
            to_end.add(a)

    if len(from_start & to_end) == 1:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')


if __name__ == '__main__':
    solve()