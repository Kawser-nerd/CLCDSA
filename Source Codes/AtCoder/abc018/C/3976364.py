def func(r, c, k, s):
    table = [[[0, 0] for _ in range(c)] for _ in range(r)]
    total = [[0 for _ in range(c)] for _ in range(r)]
    # [???????????, ???????????]
    for i in range(r):
        for j in range(c):
            # print("i:{} j:{}".format(i, j))
            if s[i][j] == "o":
                table[i][j][0] = 1
                table[i][j][1] = 1
            if i > 0 and j > 0:
                table[i][j][0] += table[i - 1][j - 1][0]
            if i > 0 and j < len(s[0]) - 1:
                table[i][j][1] += table[i - 1][j + 1][1]
    #for i in range(len(table)):
    #    print(table[i])

    # s[k-1][k-1]??????????"o"???
    # ????????1????????
    # "o"??????????imos???????"o"?????
    _sum = 0
    for i in range(r):
        for j in range(c):
            if abs(k - 1 - i) + abs(k - 1 - j) < k and s[i][j] == "o":
                _sum += 1
    total[k - 1][k - 1] = _sum
    count = 0
    if _sum == 2 * (k ** 2) - 2 * k + 1:
        count += 1
    # print("_sum:{}".format(_sum))
    for i in range(k - 1, r - (k - 1)):
        if k - 1 < i:
            # ???????,?j==k-1?
            # ????????
            _sum = total[i - 1][k-1]
            _sum += table[i + (k - 1)][k - 1][0] - table[i][0][0]
            if s[i][0] == "o":
                _sum += 1
            _sum += table[i + (k - 1)][k - 1][1] - table[i][2 * (k - 1)][1]
            # print("table[{}][{}][1]:{} - table[{}][{}][1]:{}".format(i + k - 1, k - 1, table[i + (k - 1)][k - 1][
            # 1], i, 2 * (k - 1), table[i][2 * (k - 1)][1]))
            if s[i][2 * (k - 1)] == "o":
                _sum += 1
            # ??????
            if s[i + (k - 1)][k - 1] == "o":
                _sum -= 1
            # print("i:{} j:{} _sum:{}".format(i, k - 1, _sum))
            # ????????
            _sum -= table[i - 1][2 * (k - 1)][0] - table[i - 1 - (k - 1)][k - 1][0]
            if s[i - 1 - (k - 1)][k-1] == "o":
                _sum -= 1
            # print(_sum)
            _sum -= table[i - 1][0][1] - table[i - 1 - (k - 1)][k - 1][1]
            # print(_sum)
            total[i][k - 1] = _sum
            if _sum == 2 * (k ** 2) - 2 * k + 1:
                count += 1
        # ???????
        for j in range(k, c - (k - 1)):
            # ????????
            _sum += table[i][j + (k - 1)][0] - table[i - (k - 1)][j][0]
            if s[i - (k - 1)][j] == "o":
                _sum += 1
            _sum += table[i + (k - 1)][j][1] - table[i][j + (k - 1)][1]
            # print("i:{} j:{} _sum:{}".format(i, j, _sum))

            # ????????
            _sum -= table[i][j - (k - 1) - 1][1] - table[i - (k - 1)][j - 1][1]
            if s[i - (k - 1)][j - 1] == "o":
                _sum -= 1
            #print("table[{}][{}][1]:{} - table[{}][{}][1]:{}".format(
            #    i, j - (k - 1) - 1, table[i][j - (k - 1) - 1][1], i - k + 1, j - 1, table[i - k + 1][j - 1][1]))
            #print(_sum)
            _sum -= table[i + (k - 1)][j - 1][0] - table[i][j - 1 - (k - 1)][0]
            total[i][j] = _sum
            if _sum == 2 * (k ** 2) - 2 * k + 1:
                count += 1
    # for i in range(len(total)):
        # print(total[i])
    return count


"""
r, c, k = [4, 5, 2]
s = [['x', 'o', 'o', 'o', 'o'], ['o', 'o', 'o', 'o', 'x'], ['o', 'o', 'o', 'o', 'o'], ['o', 'x', 'x', 'o', 'o']]
out = func(r, c, k, s)
print("1 {}vs{} {}".format(out, 3, out == 3))
r, c, k = [4, 5, 2]
s = ["ooooo", "oxoox", "oooox", "oxxoo"]
out = func(r, c, k, s)
print("2 {}vs{} {}".format(out, 0, out == 0))
r, c, k = [8, 6, 3]
s = ['oooooo', 'oooooo', 'oooooo', 'oooooo', 'oxoooo', 'oooooo', 'oooooo', 'oooooo']
out = func(r, c, k, s)
print("3 {}vs{} {}".format(out, 4, out == 4))
"""
r, c, k = [int(i) for i in input().split()]
s = [["0" for _ in range(c)] for _ in range(r)]
for i in range(len(s)):
    s[i] = input()
print(func(r, c, k, s))