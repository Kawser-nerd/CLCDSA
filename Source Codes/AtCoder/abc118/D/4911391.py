n, _ = map(int, input().split())
numbers = list(map(int, input().split()))
reqs = {
    1: 2,
    2: 5,
    3: 5,
    4: 4,
    5: 5,
    6: 6,
    7: 3,
    8: 7,
    9: 6,
}

memo = {}


def max_counts(a, b):
    """
    a ? b ???????
    :param a: solve() ????
    :param b: solve() ????
    :return:
    """
    if a is None:
        return b
    if b is None:
        return a
    # ????????????
    if sum(a) > sum(b):
        return a
    if sum(a) < sum(b):
        return b
    # ??????????????????????
    for a_c, b_c in zip(reversed(a), reversed(b)):
        if a_c > b_c:
            return a
        if a_c < b_c:
            return b
    return a


# https://atcoder.jp/contests/abc118/submissions/4911280
# DP ?
memo[0] = [0 for _ in range(10)]
for i in range(n):
    if i in memo:
        for num in numbers:
            next_n = i + reqs[num]
            next_counts = memo[next_n] if next_n in memo else None
            if next_n <= n:
                memo[next_n] = max_counts(
                    next_counts,
                    memo[i][:num] + [memo[i][num] + 1] + memo[i][num + 1:]
                )

ans = ''
for num in range(9, 0, -1):
    for _ in range(memo[n][num]):
        ans += str(num)
print(ans)