# -*- coding: utf-8 -*-


def main():
    n = int(input())
    a = list(map(int, input().split()))
    count = len((set(a)))

    if count % 2 == 0:
        count -= 1

    print(count)


if __name__ == '__main__':
    main()