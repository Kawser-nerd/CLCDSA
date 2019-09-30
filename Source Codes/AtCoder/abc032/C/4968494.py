def main():
    result = sub()
    print(result)


def sub():
    n, k = [int(x) for x in input().split()]
    ss = [int(input()) for i in range(n)]

    result = 0
    right = 0

    for s in ss:
        if s == 0:
            return n
    # 0. left???
    acc = 1
    for left in range(n):
        # 1. ????right????
        while(right < n):
            tmp = acc * ss[right]
            if tmp <= k:
                acc = tmp
                right = right + 1
                length = right - left
                result = max(length, result)
            else:
                break

        if left == right:
            right = right + 1
            continue

        acc = acc / ss[left]
        if acc <= k:
            length = right - left
            result = max(length, result)
        else:
            continue
    return result


if __name__ == '__main__':
    main()