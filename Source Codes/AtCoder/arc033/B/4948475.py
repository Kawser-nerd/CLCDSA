# -*- coding: utf-8 -*-


def main():
    na, nb = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    print(len(set(a) & set(b)) / len(set(a + b)))


if __name__ == '__main__':
    main()