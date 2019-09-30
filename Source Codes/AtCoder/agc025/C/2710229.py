import sys


def get_checks(lefts, rights, used):
    def left_check(pos):
        while lefts:
            e, i = lefts.pop()
            if not used[i]:
                break
        else:
            return None

        used[i] = True
        if pos >= e:
            return None
        return e

    def right_check(pos):
        while rights:
            e, i = rights.pop()
            if not used[i]:
                break
        else:
            return None

        used[i] = True
        if pos <= e:
            return None
        return e

    return left_check, right_check


def simulate(left_first=True):
    ans = 0
    pos = 0
    _lefts = lefts.copy()
    _rights = rights.copy()
    used = [False] * n
    left_check, right_check = get_checks(_lefts, _rights, used)
    funcs = [left_check, right_check] if left_first else [right_check, left_check]
    dir = 0

    while True:
        e = funcs[dir](pos)
        if e is None:
            break
        ans += abs(e - pos)
        pos = e
        dir ^= 1
    ans += abs(pos)
    return ans


n = int(input())
lefts, rights = [], []
for i, line in enumerate(sys.stdin.readlines()):
    l, r = map(int, line.split())
    lefts.append((l, i))
    rights.append((r, i))

lefts.sort()
rights.sort(reverse=True)

lf = simulate(True)
rf = simulate(False)

print(max(lf, rf))