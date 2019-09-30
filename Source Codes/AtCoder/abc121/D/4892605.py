def solve(string):
    a, b = map(int, string.split())
    if b == 0:
        return "0"
    bin_a = "{:040b}".format(a)
    bin_b = "{:040b}".format(b)
    aa = [-1 if _a == "0" else int(bin_a[i + 1:] or "0", 2) for i, _a in enumerate(bin_a)]
    bb = [-1 if _b == "0" else int(bin_b[i + 1:] or "0", 2) for i, _b in enumerate(bin_b)]
    index = 0
    while True:
        if bb[index] != -1:
            break
        index += 1
    ans = []
    for i in range(index, 40):
        tmp = 0
        tmp += (bb[i] + 1) % 2 if bb[i] >= 0 else 0
        tmp += aa[i] % 2 if aa[i] > 0 else 0
        ans.append(str(tmp % 2))
    ans[-1] = str((b - a) // 2 % 2) if a % 2 == b % 2 == 0 else str(((b - a) // 2 + 1) % 2)
    return str(int("".join(ans), 2))


if __name__ == '__main__':
    print(solve(input()))