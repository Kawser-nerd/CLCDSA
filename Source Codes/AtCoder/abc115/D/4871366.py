nums = [0] * 51
ps = [0] * 51


def calc(l, x):
    global nums, ps

    if l == 0:
        if x == 0:
            return 0
        else:
            return 1

    if x == 1:
        return 0
    elif x <= 1 + nums[l - 1]:
        return calc(l - 1, x - 1)
    elif x == 2 + nums[l - 1]:
        return ps[l - 1] + 1
    elif x <= 2 + 2 * nums[l - 1]:
        return ps[l - 1] + 1 + calc(l - 1, x - 2 - nums[l - 1])
    else:
        return ps[l]


def main():
    global nums, ps
    nums[0] = 1
    ps[0] = 1
    for i in range(len(nums)):
        if i == 0:
            continue
        nums[i] = 2 * nums[i - 1] + 3
        ps[i] = 2 * ps[i - 1] + 1

    n, x = map(int, input().split())
    print(calc(n, x))


if __name__ == "__main__":
    main()