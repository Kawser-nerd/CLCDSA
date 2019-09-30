from bisect import insort_left

def by_points(x, y):
    return x[1] - y[1]

def by_turns(x, y):
    return x[2] - y[2]

def by_cards(x, y):
    return x[0] - y[0]

def solver(hand, deck, turns=1, points=0):
    while turns > 0:
        print hand
        print deck
        print turns
        print points
        # [c, s, t]
        # get the next best card play
        # increase turns if possible
        hand.sort(cmp=by_turns, reverse=True)
        print 'hand sorted by turns', hand
        if len(hand) and hand[0][2] > 0:
            print 'playing turn gainer'
            to_play = hand.pop(0)
            print to_play
            turns += to_play[2] - 1
            points += to_play[1]
            for c in xrange(to_play[0]):
                if len(deck):
                    hand.append(deck.pop(0))
            continue
        # current points
        hand.sort(cmp=by_points, reverse=True)
        points_in_hand =  sum([x[1] for x in hand[:turns]])
        if turns > 1:
            hand.sort(cmp=by_cards, reverse=True)
            if len(hand) and hand[0][0] > 0:
                to_play = hand.pop(0)
                if_played = solver(hand + deck[:to_play[0]], deck[to_play[0]:], turns=turns-1, points=points+to_play[1])
                if if_played > points_in_hand + points:
                    return if_played
                else:
                    return points_in_hand + points
            else:
                return points + points_in_hand
        else:
            return points + points_in_hand
    if turns:
        hand.sort(cmp=by_points, reverse=True)
        points += sum([x[1] for x in hand[:turns]])
    return points
                    


def ssi(s):
    """
    space separated integers
    """
    return map(int, s.strip('\n').split())

def main():
    # open input file
    input_file = open('infile.txt')
    cases = int(input_file.readline())
    output = []
    # loop through cases passing input to solver
    for c in range(cases):
        print 'Case: ', c
        num_hand = int(input_file.readline())
        hand = []
        for r in xrange(num_hand):
            hand.append(ssi(input_file.readline()))
        num_deck = int(input_file.readline())
        deck = []
        for r in xrange(num_deck):
            deck.append(ssi(input_file.readline()))
        answer = solver(hand, deck)
        output.append('Case #%d: %s\n' % (c+1, str(answer)))
    input_file.close()
    # open output file
    output_file = open('outfile.txt', 'w')
    # write ouput to file
    output_file.writelines(output)
    # close out file
    output_file.close()
    print 'Done!'



if __name__=='__main__':
    main()
