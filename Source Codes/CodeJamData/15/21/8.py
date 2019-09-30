def f(n):
    if n == 1:
        return 1

    if str(n)[-1] == "0":
        # Multiples of 10
        return 1 + f(n-1)

    s = str(n)
    k = int("1" + (len(s) - 1) * "0")

    a = -k # No reverse
    b = 0 # Reverse

    for i in range(len(s)):
        a += int(s[~i]) * 10**i
        b += int(s[~i]) * 10**min(i, len(s)-i-1)

    return min(a, b) + f(k)

with open("A-large.in") as infile:
    with open("A.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            n = int(next(infile))

            print("Case #{}: {}".format(case, f(n)), file=outfile)

