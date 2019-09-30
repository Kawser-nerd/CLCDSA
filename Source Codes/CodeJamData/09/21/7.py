#!/usr/bin/env python

def parse():
    global tokens
    assert tokens[0] == '('
    prob = float(tokens[1])
    if tokens[2] == ')':
        tokens = tokens[3:]
        return [prob, None, None, None]

    feature = tokens[2]
    tokens = tokens[3:]
    child1 = parse()
    child2 = parse()
    tokens = tokens[1:]
    return [prob, feature, child1, child2]

def main():
    f = open("A.in", "rt")
    T = int(f.readline().strip())
    for t in range(T):
        N = int(f.readline().strip())
        lines = []
        for i in range(N):
            lines.append(f.readline())
        tree = " ".join(lines)
        tree = tree.replace("(", " ( ")
        tree = tree.replace(")", " ) ")

        global tokens
        tokens = tree.split()
        tree = parse()

        print "Case #%s:" % (t + 1)
        M = int(f.readline().strip())
        for i in range(M):
            list = f.readline().split()
            name = list[0]
            count = int(list[1])
            features = set(list[2:])
            assert len(features) == count

            root = tree
            prob = 1
            while root[1] != None:
                prob *= root[0]
                if root[1] in features:
                    root = root[2]
                else:
                    root = root[3]
            prob *= root[0]
            print "%.7f" % prob
    return 0

if __name__ == "__main__":
    main()

