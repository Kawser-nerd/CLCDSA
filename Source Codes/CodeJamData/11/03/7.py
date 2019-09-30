# Candy Splitting Google Code Jam
# zbanks Zach Banks zach@zbanks.net
# Python

xsum = lambda x: reduce(lambda v, s: v ^ s, x)

def main():
    f = open("input.txt")
    testlen = int(f.readline().strip())
    tests = []
    i = 0
    for line in f:
        if i % 2:
            tests.append(line.strip())
        i += 1

    tests = tests[:testlen]

    for test, i in zip(tests, range(testlen)):
        print "Case #%d: %s" % (i+1, solve(parse(test)))

def parse(test):
    return map(int, test.split(" "))

def solve(test):
    if xsum(test) != 0:
        return "NO"
    else:
        return str(sum(test) - min(test))


if __name__ == "__main__":
    main()
