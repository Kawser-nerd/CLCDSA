import copy


memo = dict()
# memo = [- 10 ** 10 for _ in range(1 << 10 + 10)]
# print(len(memo))


def search(_accessible, left, maxTurn, _table):
    def write_memo():
        return "".join([c for c in [''.join(map(str, _table[i])) for i in range(3)]])
    # print("left:{}".format(left))
    if left == 0:  # ????????????????
        score = 0
        for _i in range(2):
            for _j in range(3):
                if (_table[_i][_j] == "o" and _table[_i + 1][_j] == "o") \
                        or (_table[_i][_j] == "x" and _table[_i + 1][_j] == "x"):
                    score += b[_i][_j]
        for _i in range(3):
            for _j in range(2):
                if (_table[_i][_j] == "o" and _table[_i][_j + 1] == "o") \
                        or (_table[_i][_j] == "x" and _table[_i][_j + 1] == "x"):
                    score += c[_i][_j]
        # print("table:{} score:{}".format(_table, score))
        """
        print()
        for i in range(3):
            print(_table[i])
        print(score)
        """
        return score
    else:
        counter = 0
        # ??counter???????????
        """
        for i in range(3):
            for j in range(3):
                if _table[i][j] == "":
                    # ???==""????
                    # ??=="o"????????
                    # ???""?????????????
                    # "o"????????????
                    # "o"?????"x"?????????
                    # ?????????
                    counter += 1 << (3 * i + j + 1)
        """
        # ???????????????
        _writeMemo = write_memo()
        if _writeMemo and (_writeMemo in memo.keys()):
            return memo[_writeMemo]
        # if memo[counter] != - 10 ** 10:
            # print("cut")
            # return memo[counter]
        _max = -10 ** 10
        _min = 10 ** 10
        for i in range(3):
            for j in range(3):
                if _accessible[i][j]:
                    accessible = copy.deepcopy(_accessible)
                    accessible[i][j] = False
                    table = copy.deepcopy(_table)
                    if maxTurn:
                        table[i][j] = "o"
                        _max = max(_max, search(accessible, left - 1, not maxTurn, table))
                    else:
                        table[i][j] = "x"
                        _min = min(_min, search(accessible, left - 1, not maxTurn, table))
        if maxTurn:
            # print("maxTurn:{}".format(_max))
            memo[write_memo()] = _max
            # memo[counter] = _max
            # print("max memo[{}]:{} left:{}".format(counter, memo[counter], left))
            return _max
        else:
            # print("mini")
            # print("min memo[{}]:{} left:{}".format(counter, memo[counter], left))
            memo[write_memo()] = _min
            # memo[counter] = _min
            return _min

b = [[0 for _ in range(3)] for _ in range(2)]
c = [[0 for _ in range(2)] for _ in range(3)]
for i in range(2):
    b[i] = [int(i) for i in input().split()]
for i in range(3):
    c[i] = [int(i) for i in input().split()]

# b = [[18, 22, 15], [11, 16, 17]]
# c = [[4, 25], [22, 15], [10, 4]]
# b = [[0, 15, 0], [0, 0, 25]]
# c = [[20, 10], [0, 0], [25, 0]]
totalScore = sum(b[0]) + sum(b[1]) + sum(c[0]) + sum(c[1]) + sum(c[2])
_accessible = [[True for _ in range(3)] for _ in range(3)]
_table = [["." for _ in range(3)] for _ in range(3)]
naoki = search(_accessible, 9, True, _table)
print(naoki)
print(totalScore - naoki)
# print(memo)
"""
_max = 0
N = [i for i in range(9)]  # N = bit??????
# N?????????????
for i in range(1, 1 << len(N)):
    output = []
    selected = [0 for _ in range(9)]
    for j in range(len(N)):
        if ((i >> j) & 1) == 1:
            output.append(j)  # ??j???????index?1?
            selected[j] = 1
    if len(output) == 5:
        # ??????
        score = 0
        naoko = 0
        for _i in range(2):
            for _j in range(3):
                # print("i:{} j:{}".format(_i, _j))
                # print("s1:{} s2:{}".format(_i * 3 + _j, (_i+1) * 3 + _j))
                if selected[_i * 3 + _j] == 1 \
                        and selected[(_i + 1) * 3 + _j] == 1:
                    score += b[_i][_j]
                else:
                    naoko += b[_i][_j]
        for _i in range(3):
            for _j in range(2):
                if selected[_i + 3 * _j] == 1 \
                        and selected[_i + 1 + 3 * _j] == 1:
                    score += c[_i][_j]
                else:
                    naoko += c[_i][_j]
        print("score:{} vs {}".format(score, naoko))
        # print(output)
"""