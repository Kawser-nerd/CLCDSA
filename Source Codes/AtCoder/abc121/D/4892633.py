def solve(string):
    a, b = map(int, string.split())
    if b == 0:
        return "0"
    bin_a = "{:040b}".format(a)
    bin_b = "{:040b}".format(b)
    aa = [-1 if _a == "0" else int(bin_a[i + 1:] or "0", 2) for i, _a in enumerate(bin_a)]
    bb = [-1 if _b == "0" else int(bin_b[i + 1:] or "0", 2) for i, _b in enumerate(bin_b)]
    ans = [str((bb[i] + 1 + max(0, aa[i])) % 2) for i in range(bin_b.index("1"), 40)]
    ans[-1] = str((b - a) // 2 % 2) if a % 2 == b % 2 == 0 else str(((b - a) // 2 + 1) % 2)
    return str(int("".join(ans), 2))


if __name__ == '__main__':
    print(solve(input()))