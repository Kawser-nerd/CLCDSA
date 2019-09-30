import sys

def the_killer_word(words, letter_lists):
    result = []
    for letters in letter_lists:
        scores = [0 for i in range(len(words))]
        for a, word in enumerate(words):
            possibs = [i for i in words if len(i) == len(word)]
            for l in letters:
                if len(possibs) == 1: break
                if any(l in p for p in possibs):
                    if l not in word:
                        scores[a] += 1
                        possibs = [k for k in possibs if l not in k]
                        continue
                    c = word.count(l)
                    for n, j in enumerate(word):
                        if l == j: possibs = [k for k in possibs
                                              if k[n] == j and k.count(j) == c]
        result += [words[scores.index(max(scores))]]
    return ' '.join(result)

def main(filename):
    Input = open(filename, 'r').read().split('\n')
    Output = ""
    x = 0
    for i in range(1, int(Input[0]) + 1):
        n = Input[i+x].split(' ')
        a = int(n[0]); b = int(n[1])
        words = [Input[i+x+j] for j in range(1, a + 1)]
        letter_lists = [Input[i+x+a+j] for j in range(1, b + 1)]
        x += a + b
        result = the_killer_word(words, letter_lists)
        Output += "Case #" + str(i) + ": " + result + "\n"
    open(filename[:-3] + ".out", 'w').write(Output)

if __name__ == "__main__": main(sys.argv[1])
