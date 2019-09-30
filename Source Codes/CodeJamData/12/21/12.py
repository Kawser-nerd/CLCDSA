def wcs(score, points):
    "worst case scenario, distributing points among scores"
    s = sorted(score)
    pos = 0
    points = 1.0 * points
    if (sum(score) + points) / len(score) > max(score):
        return (sum(score) + points) / len(score)

    while(points > 0):
        if pos >= (len(s) - 1):
            alloc = points / len(s)
            points = 0
        else:
            alloc = min(points / (pos + 1), s[pos+1] - s[pos])
            points -= alloc * (pos + 1)
        for i in range(pos+1):
            s[i] += alloc
        if points == 0:
            return min(s)
        pos += 1
    return min(s)

def find_fraction(score, others):
    tot = score + sum(others)
    lo, hi = 0, tot
    while (hi - lo) > 1e-7:
        mid = (hi + lo) / 2.
        s1 = score + mid
        s2 = wcs(others, tot - mid)
        if s1 > s2:
            hi = mid
        else:
            lo = mid
    return (hi + lo) / 2. / tot

def solve(scores):
    result = [0] * len(scores)
    tscore = sum(scores)

    target = max( max(scores), 2 * tscore / len(scores))

    for i,s in enumerate(scores):
        result[i] = 100. * (target - scores[i]) / tscore
    return result

def solve2(scores):
    result = [0] * len(scores)
    for i in range(len(scores)):
        other = [scores[j] for j in range(len(scores)) if j != i]
        result[i] = find_fraction(scores[i], other) * 100
    return result

def main():
    import sys
    data = open(sys.argv[1]+'.in').readlines()
    with open(sys.argv[1]+'.out', 'w') as out:
        for i, line in enumerate(data[1:]):
            nums = map(int, line.strip().split())[1:]
            answer = ' '.join(map(str, solve2(nums)))
            response = "Case #%i: %s\n" % (i+1, answer)
            print response
            out.write(response)

def test():
    print solve2([20, 10])
    print solve2([10, 0])
    print solve2([25, 25, 25, 25])
    print solve2([24, 30, 21])
    print solve2([0, 0, 74, 0, 0])

if __name__ == "__main__":
    #test()
    main()