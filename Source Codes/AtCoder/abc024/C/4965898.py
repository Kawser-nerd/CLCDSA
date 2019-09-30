def ethnic_large_movement(N: int, D: int, K: int, LR: list, ST: list)->list:
    ret = [0] * K
    defined = 0

    for d, (l, r) in enumerate(LR):
        for k, (s, t) in enumerate(ST):
            if ret[k] > 0:
                continue

            if s < t:
                # ?????????
                if r < s or s < l:
                    # (l, r) ? s ???????????
                    continue

                if r < t:
                    # ????????????
                    # sortedST[k] = (r, t, k)
                    ST[k] = (r, t)
                else:
                    # ?????????
                    # sortedST[k] = (t, t, k)
                    ST[k] = (t, t)
                    ret[k] = d + 1
                    defined += 1
            else:
                # ?????????
                if r < s or s < l:
                    # (l, r) ? s ???????????
                    continue

                if t < l:
                    # ????????????
                    # sortedST[k] = (l, t, k)
                    ST[k] = (l, t)
                else:
                    # ?????????
                    # sortedST[k] = (t, t, k)
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