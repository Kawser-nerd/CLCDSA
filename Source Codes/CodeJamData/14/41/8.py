__author__ = 'Pavel Mavrin'

fin = open("A.in")
fout = open("A.out", "w")
test_num = int(fin.readline())


def solve_test():
    n, x = [int(x) for x in fin.readline().split()]
    s = [int(x) for x in fin.readline().split()]
    s.sort()
    res = 0
    j = n - 1
    for i in range(n):
        while j > i and s[i] + s[j] > x:
            j -= 1
        if j > i:
            res += 1
            j -= 1
        else:
            break
    return str(res + (n - 2 * res))


for test_i in range(test_num):
    s = "Case #" + str(test_i + 1) + ": " + solve_test()
    print(s)
    print(s, file=fout)

fin.close()
fout.close()

