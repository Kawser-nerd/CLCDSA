def main():
    queen_pos_list = []
    for i in range(8):
        for j, c in enumerate(input().rstrip()):
            if c == 'Q':
                queen_pos_list.append((i, j))

    # initial check
    if not initial_check(queen_pos_list, queen_cnt=3):
        print('No Answer')
        return

    res = put_queen(queen_pos_list, queen_cnt=3)

    if res is not None:
        res_map = [['Q' if (i, j) in res else '.' for j in range(8)] for i in range(8)]
        for i in range(8):
            print("".join(res_map[i]))
        return

    print('No Answer')


def initial_check(queen_pos_list, queen_cnt):
    queen_pos_y_list = [y for y, _ in queen_pos_list]
    queen_pos_x_list = [x for _, x in queen_pos_list]

    # vertical or horizontal
    if len(set(queen_pos_y_list)) < queen_cnt or len(set(queen_pos_x_list)) < queen_cnt:
        return False

    # 45 degree
    for i in range(queen_cnt):
        t_queen_pos = queen_pos_list[i]
        for j in range(i+1, queen_cnt):
            if abs(t_queen_pos[0] - queen_pos_list[j][0]) == abs(t_queen_pos[1] - queen_pos_list[j][1]):
                return False

    return True


def put_queen(queen_pos_list, queen_cnt):
    if queen_pos_list is None:
        return None

    queen_pos_y_list = [y for y, _ in queen_pos_list]
    queen_pos_x_list = [x for _, x in queen_pos_list]

    if queen_cnt == 8:
        return queen_pos_list

    next_i = -1
    for i in range(8):
        # horizontal
        if i not in queen_pos_y_list:
            next_i = i
            break

    for next_j in range(8):
        # vertical
        if next_j in queen_pos_x_list:
            continue

        # 45 degree
        if any(abs(y - next_i) == abs(x - next_j) for y, x in queen_pos_list):
            continue

        n_queen_pos_list = queen_pos_list[:]
        n_queen_pos_list = sorted(n_queen_pos_list + [(next_i, next_j)], key=lambda t: t[0])

        res = put_queen(n_queen_pos_list, queen_cnt + 1)
        if res is not None:
            return res

    return None


if __name__ == '__main__':
    main()