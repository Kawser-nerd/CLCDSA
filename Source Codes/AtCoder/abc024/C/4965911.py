def ethnic_large_movement(N: int, D: int, K: int, LR: list, ST: list)->list:
    ret = [0] * K
    defined = 0

    for d, (l, r) in enumerate(LR):
        for k, (s, t) in enumerate(ST):
            if ret[k] > 0:
                continue

            if r < s or s < l:
                # (l, r) ? s ???????????
                continue

            if s < t and r < t:
                # ??????????????????????
                ST[k] = (r, t)
                continue
            elif t < s and t < l:
                # ??????????????????????
                ST[k] = (l, t)
                continue

            # ?????????
            ST[k] = (t, t)
            ret[k] = d + 1
            defined += 1

        if defined == K:
            break

    return ret


if __name__ == "__main__":
    D = 0
    K = 0
    N, D, K = map(int, input().split())
    LR = [tuple(int(s) for s in input().split()) for _ in range(D)]
    ST = [tuple(int(s) for s in input().split()) for _ in range(K)]

    ans = ethnic_large_movement(N, D, K, LR, ST)
    for a in ans:
        print(a)