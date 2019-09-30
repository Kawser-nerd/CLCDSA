from collections import defaultdict

D = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
L = [('Z', 0), ('X', 6), ('W', 2), ('S', 7), ('G', 8), ('T', 3), ('V', 5), ('F', 4), ('I', 9), ('N', 1)]

def solve(S):
    C = defaultdict(int)
    for c in S:
        C[c] += 1

    R = [0] * 10
    for c, d in L:
        n = C[c]
        R[d] += n
        for i in D[d]:
            C[i] -= n

    return ''.join(str(d) for d in range(10) for _ in range(R[d]))


t = int(input())

for i in range(t):
    S = input()
    print('Case #{}: {}'.format(i + 1, solve(S)))
