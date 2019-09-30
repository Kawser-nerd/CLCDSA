import math
from collections import deque

n_testcases = int(input().strip())

for testcase_n in range(1, n_testcases+1):
    Hd, Ad, Hk, Ak, B, D = tuple(int(x) for x in input().split())
    visited = set()
    queue = deque()
    visited.add((Hd, Ad, Hk, Ak))
    queue.append((Hd, Ad, Hk, Ak, 0))

    res = None
    while queue:
        sta_d, atk_d, sta_k, atk_k, rounds = queue.popleft()
        new_states = [
            (Hd,    atk_d,     sta_k,                 atk_k),
            (sta_d, atk_d + B, sta_k,                 atk_k),
            (sta_d, atk_d,     sta_k,                 max(0, atk_k - D)),
            (sta_d, atk_d,     max(0, sta_k - atk_d), atk_k)]
        if any(i[2] == 0 for i in new_states):
            res = rounds + 1
            break
        #print(new_states)
        new_states = [
            (sta_d - atk_k, atk_d, sta_k, atk_k)
            for sta_d, atk_d, sta_k, atk_k in new_states
            if sta_d > atk_k]
        #print(new_states)
        for i in new_states:
            if i not in visited:
                visited.add(i)
                queue.append(i + (rounds + 1,))
                #print("adding %s" % i)

    if res is None:
        print("Case #%d: IMPOSSIBLE" % (testcase_n,))
    else:
        print("Case #%d: %d" % (testcase_n, res))
