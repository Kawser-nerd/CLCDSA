import sys

def mask(word, pattern):
    return [c if c in pattern else '_' for c in word]

def cost(word, dictionary, pattern):
    k = 0
    for i in range(26):
        part = pattern[:i]
        masked = mask(word, part)
        candidates = [word_ for word_ in dictionary
                      if mask(word_, part) == masked]
        if len(candidates) == 1:
            return k

        if any([pattern[i] in candidate for candidate in candidates]) and \
           pattern[i] not in word:
            k += 1
    return k

T = int(sys.stdin.readline())
for Case in range(T):
    answer = ''
    ss = sys.stdin.readline().split()
    N = int(ss[0])
    M = int(ss[1])
    dictionary = ['' for i in range(N)]
    patterns = ['' for i in range(M)]
    for i in range(N):
        dictionary[i] = sys.stdin.readline()[:-1]
    for i in range(M):
        patterns[i] = sys.stdin.readline()[:-1]
    
    sys.stdout.write('Case #{0}:'.format(Case + 1))
    for pattern in patterns:
        answer = dictionary[0]
        Max = cost(dictionary[0], dictionary, pattern)
        for word in dictionary:
            dictionary_ = [w for w in dictionary if len(word) == len(w)]
#            print('cost({0}) = {1}'.format(word, cost(word, dictionary_, pattern)))
            if cost(word, dictionary_, pattern) > Max:
                Max = cost(word, dictionary_, pattern)
                answer = word
        sys.stdout.write(' ' + answer)
    print()
