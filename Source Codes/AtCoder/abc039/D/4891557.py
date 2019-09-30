def image_processing_takahashi(H: int, W: int, S: list)->list:
    ret = [['#'] * W for _ in range(H)]

    def is_black(h: int, w: int)->bool:
        ''' (h, w) ???????????????????
        '''
        for dh in range(-1, 1+1):
            for dw in range(-1, 1+1):
                if h + dh < 0 or H <= h + dh:
                    continue
                if w + dw < 0 or W <= w + dw:
                    continue

                if ret[h+dh][w+dw] == '#':
                    return True
        return False

    # ???????????????????
    # ??????????????
    for h in range(H):
        for w in range(W):
            if S[h][w] == '#':
                # ??????
                continue
            # ?????????
            for dh in range(-1, 1+1):
                for dw in range(-1, 1+1):
                    if h + dh < 0 or H <= h + dh:
                        continue
                    if w + dw < 0 or W <= w + dw:
                        continue

                    ret[h+dh][w+dw] = '.'

    for h in range(H):
        for w in range(W):
            # ???????
            if S[h][w] == '.':
                # ??????????
                continue

            if not is_black(h, w):
                return []
    return list(map(''.join, ret))


if __name__ == "__main__":
    H = 0
    H, W = map(int, input().split())
    S = [input() for _ in range(H)]
    ans = image_processing_takahashi(H, W, S)

    if ans:
        print('possible')
        print('\n'.join(ans))
    else:
        print('impossible')