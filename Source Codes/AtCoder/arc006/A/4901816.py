# -*- coding: utf-8 -*-


def main():
    e = set(list(map(int, input().split())))
    b = int(input())
    l = set(list(map(int, input().split())))

    matched = len(e & l)
    bonus = b in l

    if matched == 6:
        print(1)
    elif matched == 5:
        if bonus:
            print(2)
        else:
            print(3)
    elif matched == 4:
        print(4)
    elif matched == 3:
        print(5)
    else:
        print(0)


if __name__ == '__main__':
    main()