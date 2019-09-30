def solve():
    s, k = input().split()
    k = int(k)
    a = [False if x == '-' else True for x in s]

    ans = 0
    for i in range(len(a) - k + 1):
        if not a[i]:
            ans += 1
            for pos in range(i, i + k):
                a[pos] = not a[pos]

    if all(x for x in a):
        return ans
    else:
        return "IMPOSSIBLE"


def prepare_input():
    local = False
    task = 'A'
    attempt = -1

    import sys
    if local:
        sys.stdin = open("../input.txt", "r")
    else:
        filename = "../{}-small-attempt{}".format(task, attempt) if attempt >= 0 else "../{}-large".format(task)

        sys.stdin = open(filename + ".in", "r")
        sys.stdout = open(filename + ".out", "w")


prepare_input()
tests = int(input())
for test in range(1, tests + 1):
    res = solve()
    print("Case #{}: {}".format(test, res))
