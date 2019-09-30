# -*- coding: utf-8 -*-


def main():
    c = int(input())
    boxes = list()
    ans = 1

    for i in range(c):
        boxes.append(sorted(list(map(int, input().split()))))

    for k in range(3):
        max_value = 1

        for j in range(c):
            max_value = max(max_value, boxes[j][k])

        ans *= max_value

    print(ans)


if __name__ == '__main__':
    main()