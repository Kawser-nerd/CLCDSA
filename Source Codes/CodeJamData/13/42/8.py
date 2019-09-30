def reader(inFile):
    return tuple(inFile.getInts())

# The worst player 0 can do is [W,W,W]
# The worst player 1 can do is [L,W,W]
# The worst player 2 can do is [L,W,W]
# The worst players 3-6 can do is [L,L,W,W,W,...] 

# For N = 3:
# The best player 0 can do is [W,W,W]
# The best player 1-4 can do is [W,W,L]
# The best player 5-6 can do is [W,L,L]

# For N = 4:

# The best player 0 can do is [W,W,W,W]
# The best player 1-8 can do is [W,W,W,L]
# The best player 9-12 can do is [W,W,L,L]
# The best player 13-14 can do is [W,L,L,L]
# The best player 15 can do is [L,L,L,L]

def solver((N, p)):
    wins = [(((p - 1) >> i) & 1) == 0 for i in xrange(N)][::-1]
    # print wins
    a1 = 0
    for win in wins:
        if not win:
            a1 += 1
        else:
            break
    # Player 15 cannot win if there is a true anywhere
    # Players 13-14 cannot win if there is a win at the start and at least one more win
    a1 = ((1 << (a1 + 1)) - 2) if (a1 < N) else ((1 << N) - 1)
    a2 = 0
    for win in wins:
        if win:
            a2 += 1
        else:
            break
    if (a2 == len([win for win in wins if win])):
        a2 -= 1
    a2 = (1 << N) - (1 << (a2 + 1))
    return "%d %d" % (a1, a2)

if __name__ == "__main__":
    from GCJ import GCJ
    GCJ(reader, solver, "/Users/lpebody/gcj/2013_2/b/", "b").run()
