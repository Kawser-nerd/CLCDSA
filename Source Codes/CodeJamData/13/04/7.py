from itertools import chain
import sys


sys.setrecursionlimit(300)


def lex_cmp(path, best):
    for p, b in zip(path, best):
        if p > b:
            return False
        elif p < b:
            return True
    return True


def yoba(keys, chests, path=(), best=()):

    if not check(keys, chests):
        return best

    if not lex_cmp(path, best):
        return best

    if len(chests) == 0 and lex_cmp(path, best):
        best = path

    for i in range(len(chests)):
        index, curr_key, keys_inside = chests[i]
        if curr_key in keys:
            ik = keys.index(curr_key)
            best = yoba(keys[:ik] + keys[ik + 1:] + keys_inside, chests[:i] + chests[i + 1:], path + (index,), best)
            if best and lex_cmp(best, tuple(range(1, len(best)))):
                break

    return best


def check(keys, chests):
    all_keys = keys
    need_keys = ()

    for index, curr_key, keys_inside in chests:
        all_keys = all_keys + keys_inside
        need_keys = need_keys + (curr_key,)

    for key in set(need_keys):
        if all_keys.count(key) < need_keys.count(key):
            return False

    tchests = chests
    tkeys = set(keys)
    while tchests:
        can_open = tuple(map(lambda c: c[2], filter(lambda c: c[1] in tkeys, tchests)))
        if not can_open:
            return False
        tchests = tuple(filter(lambda c: c[1] not in tkeys, tchests))
        tkeys |= set(chain.from_iterable(filter(bool, can_open)))

    return True


for i in range(int(input())):
    k, n = tuple(map(int, input().split()))
    keys = tuple(map(int, input().split()))
    chests = ()
    for j in range(n):
        t = tuple(map(int, input().split()))
        chests = chests + ((j + 1, t[0], t[2:]), )

    print("Case #{}: {}".format(i + 1, " ".join(map(str, yoba(keys, chests))) or "IMPOSSIBLE"))
