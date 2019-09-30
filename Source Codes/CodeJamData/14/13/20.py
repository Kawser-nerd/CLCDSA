import math

SCALEFACTOR = 2
SCALEFACTOR2 = 0.8

def getProbability(position, number, N=1000):
    N = float(N)
    if number > position:
        p = math.sqrt(position ** 2 + (N-number) ** 2) / N
    else:
        p = math.sqrt((position - N/2) ** 2 + (number - N/2) ** 2) / N * SCALEFACTOR2

    return 1/N - (1/N) * SCALEFACTOR +  (p * 2 * (1/N) * SCALEFACTOR)

with open('C.in') as f:
    with open('C.out', 'w') as f2:
        lines = f.readlines()
        output = ""
        scores = []
        for i in range(int(lines[0])):
            permutation = [int(n) for n in lines[2 + i*2].split(" ")]
            score = 0
            for q in range(len(permutation)):
                # print(getProbability(q, permutation[q], len(permutation)))
                score = score + getProbability(q, permutation[q], len(permutation))
            scores.append(score)

        median = sorted(scores)[60]
        for i in range(len(scores)):
            score = scores[i]
            output += "Case #" + str(i+1) + ": "
            if score > median:
                output += "BAD"
            else:
                output += "GOOD"
            output += "\n"

        print(output)
        f2.write(output)