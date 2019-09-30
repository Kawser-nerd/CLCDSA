def b_paint_line(N, R, S):
    try:
        # ???????????????????????
        ans = max(S.rindex('.') - R + 1, 0)
    except ValueError:
        return 0  # ??????????

    s = list(S)
    while s.count('.') != 0:
        # ?????????????????????????
        ans += 1
        idx = s.index('.')
        for j in range(idx, idx + R):
            if j >= N:
                break
            s[j] = 'o'
    return ans

N, R = [int(i) for i in input().split()]
S = input()
print(b_paint_line(N, R, S))