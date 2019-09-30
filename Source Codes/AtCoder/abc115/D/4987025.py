ans = 0
def count_ans(level, index, len_dic, p_dic):
    global ans
    if level == 0:
        ans += 1
    else:
        if index == 0:
            pass
        elif index == len_dic[level] // 2:
            ans += 1
            ans += p_dic[level - 1]
        elif index == len_dic[level] - 1:
            ans += p_dic[level]
        elif index > len_dic[level] // 2:
            ans += p_dic[level - 1] + 1
            index_next = index - len_dic[level - 1] - 2
            count_ans(level - 1, index_next, len_dic, p_dic)
        else:
            index_next = index - 1
            count_ans(level - 1, index_next, len_dic, p_dic)


def get_len_dic(level):
    len_dic = [1]
    for i in range(level):
        len_dic.append(len_dic[-1] * 2 + 3)
    return len_dic

def get_p_dic(level):
    p_dic = [1]
    for i in range(level):
        p_dic.append(p_dic[-1] * 2 + 1)
    return p_dic

def main():
    global ans
    level, eat_num = map(int, input().split())
    len_dic = get_len_dic(level)
    p_dic = get_p_dic(level)
    count_ans(level, eat_num - 1, len_dic, p_dic)
    print(ans)


if __name__ == '__main__':
    main()