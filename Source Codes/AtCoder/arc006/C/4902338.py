# -*- coding: utf-8 -*-


def main():
    n = int(input())
    w = [int(input()) for _ in range(n)]
    w_mins = [w[0]]

    for i in range(1, n):
        count = 0

        for index, w_min in enumerate(w_mins):
            if w[i] <= w_min:
                w_mins[index] = w[i]
                break
            else:
                count += 1

        if count == len(w_mins):
            w_mins.append(w[i])

    print(len(w_mins))


if __name__ == '__main__':
    main()