import sys, math

def solve(D, Pdt, acc):
    min_t = math.sqrt(2 * D / acc)
    add_t = 0.0
    i = 0
    while Pdt[i][0] < D:
        d = Pdt[i][0]
        my_t = math.sqrt(2 * d / acc)
        his_t = Pdt[i][1]
        add_t = max(add_t, his_t - my_t)
        i += 1
    # In the destination.
    my_t = min_t + add_t
    if Pdt[i][0] - Pdt[i-1][0] == 0:
        his_t = my_t
    else:
        his_t = Pdt[i-1][1] + (D - Pdt[i-1][0]) * (Pdt[i][1] - Pdt[i-1][1]) / (Pdt[i][0] - Pdt[i-1][0])
    return max(my_t, his_t)

C = int(sys.stdin.readline())
for c in range(C):
    sD, sP, _ = sys.stdin.readline().split()
    D, P = float(sD), int(sP)
    Pdt = []
    for p in range(P):
        Pt, Pd = map(float, sys.stdin.readline().split())
        Pdt.append((Pd, Pt))
    Acc = map(float, sys.stdin.readline().split())
    solution = [solve(D, Pdt, acc) for acc in Acc]
    print "Case #%d:\n%s" % (c + 1, "\n".join(map(str, solution)))