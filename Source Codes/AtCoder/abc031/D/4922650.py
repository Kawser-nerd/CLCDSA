def goro_awase(K: int, N: int, goro: list) -> list:
    # 3^K ?? (< 19683 ~ 2 * 10^4) ? sk ?????????
    # ?????
    for i in range(3 ** K):
        # i ? 3 ???????k ??????? n ?????
        # k ????? sk ???? n+1 ?????????
        d = {}
        for k in range(K):
            d[k+1] = (i % 3) + 1
            i //= 3

        for n, w in goro:
            # ????????? sk ????????? w ???
            # ????????????????
            assumpt_len = 0
            while n > 0:
                assumpt_len += d[n % 10]
                n //= 10

            if assumpt_len != len(w):
                # ??
                break
        else:
            # sk ????????????????
            # ????? w ????????????????
            # k ??????????????????????
            res = {}
            for n, w in goro:
                idx = 0

                digits = []
                while n > 0:
                    k = n % 10
                    n //= 10
                    digits.append(k)

                for k in reversed(digits):
                    sk = w[idx:idx + d[k]]
                    idx = idx + d[k]
                    if k in res and res[k] != sk:
                        break
                    res[k] = sk
                else:
                    # while ?????
                    continue
                # while ?????????
                break
            else:
                # ??? sk ?????????????
                return res

    return None


if __name__ == "__main__":
    N = 0
    K, N = map(int, input().split())
    goro = []
    for _ in range(N):
        v, w = input().split()
        goro.append((int(v), w))

    ans = goro_awase(K, N, goro)
    if ans is None:
        raise Exception('error')
    else:
        for _, s in sorted(ans.items()):
            print(s)