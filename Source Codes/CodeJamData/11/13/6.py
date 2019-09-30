import sys,time

class Card:
    def __init__(self, line):
        self.c,self.s,self.t = [int(x) for x in line.split()]
    def __repr__(self):
        return "({0.c},{0.s},{0.t})".format(self)

start_time = time.time()
try:
    if len(sys.argv) > 1:
        inname = sys.argv[1]
    else:
        inname = input("Enter input filename: ")

    assert inname.endswith('.in')
    outname = inname.replace('.in', '.out')

    with open(inname) as fin:
        with open(outname, 'w') as fout:
            num_cases = int(fin.readline())
            for case_idx in range(1,1+num_cases):
                if time.time() >= start_time + 5:
                    print ("[== Case %d of %d ==]" % (case_idx, num_cases))
                N = int(fin.readline())
                hand = [Card(fin.readline()) for i in range(N)]
                M = int(fin.readline())
                deck = [Card(fin.readline()) for i in range(M)]

                def attempt_small(k): # will take no more than k cards with c=1 and t=0
                    H = sorted(hand, key=lambda card:(card.t, card.c, card.s), reverse=True)
                    D = deck[:]
                    turns = 1
                    score = 0
                    while H and turns:
                        card = H.pop(0)
                        if card.c and not card.t:
                            if not k: continue # no more c=1,t=0 needed
                            k -= 1
                        score += card.s
                        H.extend(D[:card.c])
                        D = D[card.c:]
                        turns = turns - 1 + card.t
                        H.sort(key=lambda card:(card.t, card.c, card.s), reverse=True)
                    return score

                answer = max([attempt_small(k) for k in range(1+N+M)])
                print("Case #{}: {}".format(case_idx, answer), file=fout)

##                print(hand)
##                print(deck)
##                print([attempt_small(k) for k in range(1+N+M)])
##                print(answer)
##                input("Press Enter to continue")


except:
    import traceback
    print("Exception caught:", file=sys.stderr)
    print('-'*60, file=sys.stderr)
    traceback.print_exc(file=sys.stderr)
    print('-'*60, file=sys.stderr)
    input("Press Enter to close")
else:
    total_time = time.time() - start_time
    print("Completed in %.1f seconds" % total_time, file=sys.stderr)
    time.sleep(3)
