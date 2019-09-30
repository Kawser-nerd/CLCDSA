import psyco
psyco.full()

def getline():
    return f.readline().strip()

def getint():
    return int(f.readline().strip())

def log(msg):
#    print msg
    return

def is_int(num):
    return float(num) == float(int(num))

def make_deck(num_cards):
    log("making deck for %d cards" % num_cards)
    deck = [0 for i in range(num_cards + 1)]
    log("initially %s" % deck)
    deck[0] = -1
    i = 1
    cur = 1
    while True:
        deck[cur] = i
        if i == num_cards:
            break
        i += 1
        # walk forward i times
        for x in range(i):
            # walk forward once from cur
            cur += 1
            if cur > num_cards:
                cur = 1
            while deck[cur] != 0:
                cur += 1
                if cur > num_cards:
                    cur = 1

    return deck

def do_case(case_num):
    """case_num is 1 based."""
    num_cards = int(getline())
    log(num_cards)
    out_ind = [int(s.strip()) for s in getline().split()]
    del out_ind[0]
    log(out_ind)
    
    deck = make_deck(num_cards)
    log("made deck %s" % deck)

    print "Case #" + str(case_num) + ":",
    for i in out_ind:
        print str(deck[i]),
    print ""

def main():
    global f
    f = open('C-small-attempt1.in')
    cases = getint()
    for c in range(cases):
        do_case(c + 1)

if __name__ == '__main__':
    main()
#    print find_prime_fac(20, 6)
