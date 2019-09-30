def calculate():
    r, c, w = [int(x) for x in input().split()]
    if c % w == 0 :
        return r * int(c/w) + w - 1
    else:
        return r * int(c/w) + w


def main():
    ncase = int(input())
    for i in range(ncase):
        print('Case #{}: {}'.format(i+1, calculate()))


if __name__ == '__main__':
    main()
