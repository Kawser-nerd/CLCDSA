import sys
import Numberjack #https://github.com/eomahony/Numberjack

def solve(vol, temp, sources):
    model = Numberjack.Model()
    times = Numberjack.VarArray( len(sources), 0.0, 1e100 )
    worst = Numberjack.Variable(0.0, 1e100)
    # add constraints
    # times * sources.rate == volume
    rates = [x[0] for x in sources]
    model.add(Numberjack.Sum(times, rates) == vol)
    # times * sources.rate * sources.temp == temp * vol
    tmp = [x[0] * x[1] for x in sources]
    model.add(Numberjack.Sum(times, tmp) == vol * temp)
    for i in range(len(sources)):
        model.add(worst >= times[i])
    model.add(Numberjack.Minimize(worst))
    solver = model.load("SCIP")
    solver.solve()
    if not solver.is_opt():
        return "IMPOSSIBLE"
    return "%.14f" % worst.get_value()

if __name__ == "__main__":
    f = sys.stdin
    cases = int(f.readline().strip())
    for case in range(cases):
        tmp = f.readline().strip().split(" ")
        N = int(tmp[0])
        vol = float(tmp[1])
        temp = float(tmp[2])
        sources = []
        for i in range(N):
            tmp = f.readline().strip().split(" ")
            r = float(tmp[0])
            t = float(tmp[1])
            sources.append((r, t))

        result = solve(vol, temp, sources)
        print "Case #%d: %s" % (case+1, result)
