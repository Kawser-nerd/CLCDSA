import sys
stdin = sys.stdin
import collections
import functools
import Numberjack #https://github.com/eomahony/Numberjack


def solve():
    N = int(stdin.readline().strip())
    data = collections.defaultdict(list)
    for i in range(N):
        sentence = stdin.readline().strip()
        for word in sentence.split(" "):
            data[word].append(i)
    model = Numberjack.Model()
    is_english = Numberjack.VarArray(N, 0, 1)
    model.add(is_english[0] == 1)
    model.add(is_english[1] == 0)
    common = Numberjack.Variable(0, 1000000)
    zero = Numberjack.Variable(0,0)
    total = []
    for word, sentences in data.items():
        have_french = Numberjack.Variable(0, 1)
        for i in sentences:
            model.add(have_french <= is_english[i])
        # have_french is 0 if there is french, otherwise 0 or 1
        have_english = Numberjack.Variable(0, 1)
        for i in sentences:
            model.add(have_english >= is_english[i])
        # have_english is 1 if there is english, otherwise 0 or 1
        have_both = Numberjack.Variable(0, 1)
        model.add(have_both >= have_english - have_french)
        total.append(have_both)
    model.add(Numberjack.Sum(total) <= common)
    model.add(Numberjack.Minimize(common))

    solver = model.load("SCIP")
    #solver.setVerbosity(1)
    solver.solve()
    assert solver.is_opt()
    return common.get_value()

if __name__ == "__main__":
    cases = int(stdin.readline().strip())
    for case in range(cases):
        result = solve()
        print "Case #%d: %d" % (case+1, result)
