def start_process():
    X, Y, Z, K = map(int, input().split())
    A = list(map(int, input().split()))
    return

def make_data(moji, now_num):
    if now_num == 0:
        print(moji)
    else:
        make_data(moji + 'a', now_num - 1)
        make_data(moji + 'b', now_num - 1)
        make_data(moji + 'c', now_num - 1)


def main():
    num = int(input())
    make_data('', num)


if __name__ == '__main__':
    main()