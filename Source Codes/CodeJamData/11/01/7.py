# Bot Trust Google Code Jam
# zbanks Zach Banks zach@zbanks.net
# Python

other = {"B" : "O", "O" : "B"}

def main():
    f = open("input.txt")
    testlen = int(f.readline().strip())
    tests = []

    for line in f:
        tests.append(line.strip())

    tests = tests[:testlen]

    for test, i in zip(tests, range(testlen)):
        print "Case #%d: %d" % (i+1, solve(parse(test)))

def parse(test):
    test = test.split(" ")
    return zip(test[1::2], map(int, test[2::2]))

def solve(test):
    time = {"B": 0, "O": 0}
    pos = {"B": 0, "O": 0}
    total = 0
    for nc, np in test:
        d = max(abs(pos[nc] - np) - time[nc], 0)  + 1
        time[nc] = 0
        total += d
        time[other[nc]] += d
        pos[nc] = np

    return total - 1

if __name__ == "__main__":
    main()
