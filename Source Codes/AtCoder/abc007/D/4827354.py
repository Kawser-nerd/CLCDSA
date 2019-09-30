def except_4_9(length):
    # ?DP????????
    t = [[0] * 2 for _ in range(len(length)+1)]
    t[0][1] = 1
    for i in range(len(length)):
        for j in range(len(t[0])):
            n = int(length[i])
            # ????????
            if j == 0:
                t[i+1][j] += t[i][j] * 8
            # ???????
            else:
                for k in range(n+1):
                    if k in [4, 9]:
                        continue
                    # n==k?????????????
                    if n == k:
                        t[i+1][1] += t[i][j]
                    # n!=k??????????????
                    else:
                        t[i+1][0] += t[i][j]
    return sum(t[len(length)])


N, M = map(int, input().split(' '))
print(1 + M-except_4_9(str(M)) - (N-except_4_9(str(N-1))))