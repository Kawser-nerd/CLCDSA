n = int(input())
A = [int(x) for x in input().split()]


def f(isPlus):
    sum = 0
    ret = 0
    for a in A:
        sum += a
        if isPlus:
            if sum <= 0:
                ret += abs(sum) + 1
                sum = 1
        else:
            if sum >= 0:
                ret += abs(sum) + 1
                sum = -1

        isPlus = not isPlus
    return ret


a1 = f(True)
a2 = f(False)
print(min(a1, a2))