def c_coin(N, C):
    # divisor[k]: C[k]?????C[k]?????C[k]????C??????
    # ex. C => [2, 4, 8] -> divisor => [0, 1, 2]
    # 2????0??4????1??8????2??????
    divisor = (len([1 for idx2, c2 in enumerate(C) if idx1 != idx2 and c1 % c2 == 0])
               for idx1, c1 in enumerate(C))
    return '{:.12f}'.format(sum((s // 2 + 1) / (s + 1) for s in divisor))

N = int(input())
C = [int(input()) for _ in range(N)]
print(c_coin(N, C))