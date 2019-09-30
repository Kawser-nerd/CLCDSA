from GCJ import GCJ

def read(infile):
    return [int(z) for z in infile.readline().split()]

# I think that if your bet B leaves you with >=2B,
# you are better off cutting your losses and starting anew with 2B

# If it leaves you with negative money, you should max it up

# Thus the only possible strategies are:
#  Do once
# or
#  Do all

def solve(data):
    [A, M, V] = data
    probs = [(i + 0.0) / V for i in xrange(V + 1)]
    doneyet = False
    while not doneyet:
        doneyet = True
        for k in xrange(1,V):
            score = probs[k]
            for bet in xrange(1,min(k, M)+1):
                nowscore = 0.5 * probs[k - bet] + 0.5 * (probs[k + bet] if (k + bet < V) else 1.0)
                bigbet = bet
                numraises = 0
                while (bigbet << 1) <= M:
                    numraises += 1
                    bigbet = bigbet << 1
                if (2 * bigbet > k):
                   nowscore = max(nowscore, (1 - (0.5 / (1 << numraises))) * (probs[k + bet] if (k + bet < V) else 1.0))
                score = max(score, nowscore)
            if score > probs[k]:
                doneyet = False
            probs[k] = score
    for bet in xrange(min(A, M),0,-1):
        nowscore = 0.5 * probs[A - bet] + 0.5 * (probs[A + bet] if (A + bet < V) else 1.0)
        bigbet = bet
        numraises = 0
        while (bigbet << 1) <= M:
            numraises += 1
            bigbet = bigbet << 1
        if (2 * bigbet > A):
            nowscore = max(nowscore, (1 - (0.5 / (1 << numraises))) * (probs[A + bet] if (A + bet < V) else 1.0))
        if (nowscore + 0.00000001 >= probs[A]):
            return str("%.7f" % probs[A]) + " " + str(bet)
    return "Error!"

if __name__ == "__main__":
    GCJ(read, solve, "c:\\linguo\\e", "e").run()
