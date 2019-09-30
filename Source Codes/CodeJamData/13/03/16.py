# 3 is a special case
# Otherwise, contains only 1's and 2's. At most one 2

def is_palindrome(string):
    i, j = 0, len(string) - 1

    while i < j:
        if string[i] != string[j]:
            return False
        i += 1
        j -= 1

    return True

LEN = 27

def trim(string):
    while string and string[0] == '0':
        string = string[1:]
    return string

def make_palindrome(string):
    string = trim(string)
    return [string + string[::-1], string[:-1] + string[::-1]]

def candidates():
    possible = []

    for n in xrange(1, LEN + 1):
        for a in xrange(n):
            for b in xrange(a, n):
                for c in xrange(b, n):
                    for d in xrange(c, n):
                        for e in [0, n - 1]:
                            s = '0' * n
                            s = s[:a] + '1' + s[a + 1:]
                            possible += make_palindrome(s)
                            s = s[:b] + '1' + s[b + 1:]
                            possible += make_palindrome(s)
                            s = s[:c] + '1' + s[c + 1:]
                            possible += make_palindrome(s)
                            s = s[:d] + '1' + s[d + 1:]
                            possible += make_palindrome(s)
                            s = s[:e] + '2' + s[e + 1:]
                            possible += make_palindrome(s)
                            s = s[:a] + '0' + s[a + 1:]
                            possible += make_palindrome(s)
                            s = s[:b] + '0' + s[b + 1:]
                            possible += make_palindrome(s)
                            s = s[:c] + '0' + s[c + 1:]
                            possible += make_palindrome(s)
                            s = s[:d] + '0' + s[d + 1:]
                            possible += make_palindrome(s)

    possible.append(3)
    possible = list(set(possible))
    cands = []

    for p in possible:
        if p and is_palindrome(str(int(p) * int(p))):
            cands.append(int(p) * int(p))

    cands.sort()
    return cands

cands = candidates()

def lower_bound(list, num):
    lo, hi = 0, len(list)

    while lo < hi:
        mid = (lo + hi) // 2

        if list[mid] >= num:
            hi = mid
        else:
            lo = mid + 1

    return lo

for test_case in xrange(1, int(raw_input()) + 1):
    A, B = map(int, raw_input().split())
    total = lower_bound(cands, B + 1) - lower_bound(cands, A)
    print "Case #{0}: {1}".format(test_case, total)