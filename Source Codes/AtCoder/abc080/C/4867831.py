import itertools

def main():
    n = int(input())

    ans = -10 ** 9
    f = [[0 for i in range(10)] for j in range(n)]
    p = [[0 for i in range(11)] for j in range(n)]

    for i in range(n):
        f[i] = [int(i) for i in input().split()]
    for i in range(n):
        p[i] = [int(i) for i in input().split()]

    ans = -float("inf")
    for i0, i1, i2, i3, i4, i5, i6, i7, i8, i9 in itertools.product(range(2), range(2), range(2),range(2), range(2), range(2),range(2), range(2), range(2), range(2)):
        i_list = [i0, i1, i2, i3, i4, i5, i6, i7, i8, i9]
        if sum(i_list) != 0:
            value = 0
            for j in range(n):
                value += p[j][sum([i_list[_]*f[j][_] for _ in range(10)])]
            ans = max(ans, value)

    print(ans)


main()