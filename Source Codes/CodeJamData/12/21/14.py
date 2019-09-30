#!/usr/bin/python

EPSILON = 0.00000001

def solve(N, *votes):
    X = sum(votes)

    def score((i, w)):
        return votes[i] + X * w

    def rebalance(weights, rem=1):
        if rem <= EPSILON:
            return weights
        sorted_pairs = sorted(enumerate(weights), key=score)
        scores = map(score, sorted_pairs)
        t = float("inf")
        imax = N
        for i in range(N - 1):
            if scores[i + 1] - scores[i] > EPSILON:
                t = scores[i + 1]
                imax = i + 1
                break

        #print sorted_pairs, scores, t, imax, rem

        if imax * (t - scores[0]) > (rem * X):
            ret = weights[:]
            for i in range(N):
                if i < imax:
                    ret[sorted_pairs[i][0]] += rem / float(imax)
            return ret

        new_weights = weights[:]
        new_rem = rem
        w = (t - scores[0]) / float(X)
        for i in range(imax):
            new_weights[sorted_pairs[i][0]] += w
            new_rem -= w
        return rebalance(new_weights, new_rem)

    return ' '.join(map(lambda a: str(100 * a), rebalance([0] * N)))

T = int(raw_input())
for i in range(T):
    print "Case #%i: %s" % (i+1, solve(*(int(s) for s in raw_input().split(' '))))

