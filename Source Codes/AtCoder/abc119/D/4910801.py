import bisect

s_len, t_len, q = map(int, input().split())

shrines = []
temples = []
for _ in range(s_len):
    shrines.append(int(input()))
for _ in range(t_len):
    temples.append(int(input()))


def distance(s_i, t_i, x):
    """
    s_i ? t_i ????????????????????? inf ???
    """
    if 0 <= s_i < s_len and 0 <= t_i < t_len:
        s = shrines[s_i]
        t = temples[t_i]
        if s >= x <= t:
            return max(s, t) - x
        elif s <= x >= t:
            return x - min(s, t)
        else:
            return abs(s - t) + min(abs(x - t), abs(x - s))
    else:
        return float('inf')


def solve(x):
    s_i = bisect.bisect_left(shrines, x)
    t_i = bisect.bisect_left(temples, x)
    return min([
        distance(s_i, t_i, x),
        distance(s_i, t_i - 1, x),
        distance(s_i - 1, t_i, x),
        distance(s_i - 1, t_i - 1, x),
    ])


for _ in range(q):
    print(solve(int(input())))