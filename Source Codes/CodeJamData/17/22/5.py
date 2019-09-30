tests = int(input())
I = "IMPOSSIBLE"
cols = "ROYGBV"


def solve():
    c = list(map(int, input().split()))[1:]
    s = [[]] * 6
    for i in range(6):
        s[i] = [cols[i]] * c[i]

    for i in range(1, 6, 2):
        while s[i]:
            op = (i + 3) % 6
            if len(s[op]) < 2:
                if sum([len(x) for x in s]) == 2 and len(s[op]) == 1 and len(s[i]) == 1:
                    return s[op][0] + s[i][0]
                else:
                    return I

            cur = s[op].pop() + s[i].pop() + s[op].pop()
            s[op].append(cur)

    base = sorted(s[::2], key=len)[::-1]
    print(base)
    n = sum([len(x) for x in base])
    if len(base[0]) * 2 > n:
        return I

    res = [""] * n
    for i in range(len(base[0])):
        res[i * 2] = base[0][i]

    other = []
    for i in range(len(base[1]) + len(base[2])):
        if not base[1]:
            other.append(base[2].pop())
        elif not base[2]:
            other.append(base[1].pop())
        else:
            other.append(base[1 + i % 2].pop())

    other = list(reversed(other))
    for i in reversed(range(n)):
        if res[i] == "":
            res[i] = other.pop()

    return "".join(res)

for ti in range(1, tests + 1):
    print("Case #{}: {}".format(ti, solve()))
