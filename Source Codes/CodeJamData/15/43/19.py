import itertools
import time

t = time.time()

with open("C.out", "w") as outfile:
    with open("C-small-attempt1.in") as infile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            print(case)
            N = int(next(infile))

            english = set(next(infile).split())
            french = set(next(infile).split())

            common = english & french

            sentences = []

            for _ in range(N-2):
                sentences.append({w for w in next(infile).split() if w not in common})

            words = set()

            for w in english | french:
                words.add(w)

            for s in sentences:
                words |= s

            words = dict((w,i) for i,w in enumerate(sorted(words)))
            english = {words[x] for x in english}
            french = {words[x] for x in french}

            for i in range(len(sentences)):
                sentences[i] = {words[x] for x in sentences[i]}

            print(len(words), len(sentences))
                
            m = None
            
            for c in itertools.product([0, 1], repeat=len(sentences)):
                e_set = english.copy()
                f_set = french.copy()

                for a,b in zip(c, sentences):                    
                    if a == 1:
                        e_set |= b

                    else:
                        f_set |= b

                i = len(e_set & f_set)
                m = i if m is None else min(i, m)

            print("Case #{}: {}".format(N, m), file=outfile)

print(time.time() - t)
