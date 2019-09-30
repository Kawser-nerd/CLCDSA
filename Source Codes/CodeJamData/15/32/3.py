from sys import stdin
from collections import Counter


def prefix_function(s):
    for i in reversed(range(1, len(s))):
        if s[:i] == s[-i:]:
            return i
    return 0

def solve(tc):
    k, l, s = map(int, stdin.readline().split())
    keyboard_raw = stdin.readline().strip()
    word = stdin.readline().strip()

    keyboard = Counter()
    for char in keyboard_raw:
        keyboard[char] += 1. / len(keyboard_raw)

    prefixes = set()
    for i in range(len(word) + 1):
        prefixes.add(word[:i])

    pf = prefix_function(word)
    needed = ((s - len(word)) // (len(word) - pf) + 1)
    if not all(c in keyboard for c in word):
        needed = 0.

    transitions = [Counter() for _ in range(len(word) + 1)]

    def reduce(w):
        while w not in prefixes:
            w = w[1:]
        return w

    for i in range(len(word) + 1):
        for char, p in keyboard.items():
            transitions[i][len(reduce(word[:i] + char))] += p

    oldp = [ 0. for _ in range(len(word) + 1) ]
    oldp[0] = 1.

    expected = 0.

    for _ in range(s):
        newp = [ 0. for _ in range(len(word) + 1) ]
        for i in range(len(word) + 1):
            for j, p in transitions[i].items():
                newp[j] += oldp[i] * p
        oldp = newp
        expected += oldp[-1]
        # print newp

    print 'Case #%d: %.10f' % (tc, needed - expected)


if __name__ == '__main__':
    t = int(stdin.readline())
    for i in range(t):
        solve(i + 1)
