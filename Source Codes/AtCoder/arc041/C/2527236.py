def count_jump(right_list, left_list, L):
    jump_count = 0
    if len(right_list) == 0:
        for i, p in enumerate(left_list):
            jump_count += p - i - 1
    elif len(left_list) == 0:
        for i, p in enumerate(right_list):
            jump_count += L - p - i
    else:
        # ???????????????
        for i, p in enumerate(right_list):
            jump_count += right_list[-1] - p - i
        for i, p in enumerate(left_list):
            jump_count += p - left_list[0] - i

        # ?????????????????????????
        head_diff = left_list[0] - right_list[-1] - 1
        max_cnt = max(len(right_list), len(left_list))
        jump_count += head_diff * max_cnt

    return jump_count


def solve(rabbits, L):
    # ??????
    jump_count = 0
    bef_d = 'R'
    right_list = []
    left_list = []

    for n_pos, n_d in rabbits:
        # ???????????????????????JUMP??????
        if bef_d == 'L' and n_d == 'R':
            jump_count += count_jump(right_list, left_list, L)

            right_list = []
            left_list = []

        # ???????
        if n_d == 'R':
            right_list.append(n_pos)
        else:
            left_list.append(n_pos)
        # ????????
        bef_d = n_d

    jump_count += count_jump(right_list, left_list, L)

    return jump_count


if __name__ == '__main__':
    N, L = map(int, input().split())
    rabbits = []
    for _ in range(N):
        pos, direction = input().split()
        rabbits.append((int(pos), direction))
    result = solve(rabbits, L)
    print(result)