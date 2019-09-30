import itertools

def unhap(comb, r, c):
    unhappiness = 0

    for i in range(r*c):
        if i % c > 0 and comb[i] == comb[i-1] == 1:
            unhappiness += 1

        if i % c < c-1 and comb[i] == comb[i+1] == 1:
            unhappiness += 1

        if i//c > 0 and comb[i] == comb[i-c] == 1:
            unhappiness += 1

        if i//c < r-1 and comb[i] == comb[i+c] == 1:
            unhappiness += 1

    return unhappiness//2 # Double counted


def optimal(r, c, n):
    best = None
    config = None
    
    for comb in itertools.product([0, 1], repeat=r*c):
        if sum(comb) != n:
            continue

        unhappiness = unhap(comb, r, c)
        
        if best is None or unhappiness < best:
            best = unhappiness
            config = comb

    return best

    
def optimal2(r, c, n):
    grid1 = [0]*(r*c)
    grid2 = [0]*(r*c)

    corners = [0, c-1, (r-1)*c, r*c-1]
    sides = [i for i in range(r*c) if i%c == 0 or i%c == c-1 or i//c == 0 or i//c == r-1]
    
    checkerboard1 = []
    checkerboard2 = []

    for i in range(r):
        for j in range(c):
            if (i+j) % 2 == 0:
                checkerboard1.append(i*c + j)

            else:
                checkerboard2.append(i*c + j)

    strat1 = checkerboard1 + corners + sides + checkerboard2
    strat2 = checkerboard2 + corners + sides + checkerboard1

    strat1_trimmed = []
    strat1_set = set()

    for x in strat1:
        if x not in strat1_set:
            strat1_trimmed.append(x)
            strat1_set.add(x)

    strat2_trimmed = []
    strat2_set = set()

    for x in strat2:
        if x not in strat2_set:
            strat2_trimmed.append(x)
            strat2_set.add(x)

    strat1_trimmed = set(strat1_trimmed[:n])
    strat2_trimmed = set(strat2_trimmed[:n])

    sol1 = [int(i in strat1_trimmed) for i in range(r*c)]
    sol2 = [int(i in strat2_trimmed) for i in range(r*c)]

    return min(unhap(sol1, r, c), unhap(sol2, r, c))


##for r in range(1, 4):
##    for c in range(1, 7):
##        for n in range(r*c):
##            if optimal2(r,c,n) != optimal(r,c,n):
##                print(r,c,n)
    


with open("B-large.in") as infile:
    with open("B.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            print(case)
            r, c, n = map(int, next(infile).split())

            print("Case #{}: {}".format(case, optimal2(r, c, n)), file=outfile)
