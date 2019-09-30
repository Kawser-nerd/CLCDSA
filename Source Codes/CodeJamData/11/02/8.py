# Magicka Google Code Jam
# zbanks Zach Banks zach@zbanks.net
# Python

#1 EEZ 1 QE 7 QEEEERA

def main():
    f = open("input.txt")
    testlen = int(f.readline().strip())
    tests = []

    for line in f:
        tests.append(line.strip())

    tests = tests[:testlen]

    for test, i in zip(tests, range(testlen)):
        print "Case #%d: %s" % (i+1, solve(*parse(test)))

def parse(test):
    test = test.split(" ")
    comb = []
    cn = int(test[0])
    for v in test[1:cn+1]:
        comb.append((v[:2], v[:2][::-1], v[2]))
    on = int(test[cn+1])
    opps = map(tuple, test[cn+2:cn+2+on])
    seq = test[-1]
    if len(seq) != int(test[-2]):
        raise Exception("Error parsing")
        
    return (comb, opps, seq)

def solve(comb, opps, seq):
    stack = ""
    for s in seq:
        stack = s + stack
        for pair, apair, rep in comb:
            while pair in stack or apair in stack:
                stack = stack.replace(pair, rep).replace(apair, rep)
        for a, b in opps:
            if a in stack and b in stack:
                stack = ""
    return "[%s]" % ", ".join(list(stack)[::-1])

if __name__ == "__main__":
    main()
