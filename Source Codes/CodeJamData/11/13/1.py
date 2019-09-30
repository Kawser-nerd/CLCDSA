# Solution for Google Code Jam 2011 Round 1A Problem A
# Copyright (c) Dan Bjorge, 2011
# All rights reserved

import sys

def dprint(s):
    t = sys.stdout
    sys.stdout = sys.__stdout__
    print s
    sys.stdout = t

class State:
    def __init__(self, hand, deck_start, deck_end, score, turns):
        self.hand = hand
        self.deck_start = deck_start
        self.deck_end = deck_end
        self.score = score
        self.turns = turns

    def next(self, card, index):
        dprint(str(self)+" ==> "+str(card)+"@"+str(index))
        
        self.turns -= 1
        self.turns += card[2]
        self.score += card[1]
        self.hand.remove(index)
        draw_cards = min(card[0], self.deck_end - self.deck_start)
        if draw_cards > 0:
            self.hand += list(range(self.deck_start, self.deck_start+draw_cards))
            self.deck_start += draw_cards
        dprint(self)

    def __str__(self):
        return 'Hand: {!s} s{!s} t{!s} d{!s}'.format(self.hand, self.score, self.turns, self.deck_end - self.deck_start)

def solve_case(infile):
    handsize = int(infile.readline().rstrip())
    cards = []
    for i in range(handsize):
        cards.append(tuple(map(int, infile.readline().rstrip().split(' '))))
    decksize = int(infile.readline().rstrip())
    for i in range(decksize):
        cards.append(tuple(map(int, infile.readline().rstrip().split(' '))))
    hand = list(range(handsize))
    deck_start = handsize
    
    state = State(hand, deck_start, len(cards), 0, 1)
    def simplify(state):
        done = False
        while not done:
            done = True
            for card_i in state.hand:
                if cards[card_i][2] > 0:
                    done = False
                    process = cards[card_i]
                    process_i = card_i
            if not done:
                state.next(process, process_i)
                
    
    bestscore = 0
    while len(state.hand) > 0 and state.turns > 0:
        simplify(state)
        cardsbyc = ([], [], [])
        for card_i in state.hand:
            cardsbyc[cards[card_i][0]].append((cards[card_i], card_i))
        for l in cardsbyc:
            l.sort()

        if len(cardsbyc[0]) >= state.turns or len(cardsbyc[0]) == len(state.hand):
            score = state.score + sum([c[0][1] for c in cardsbyc[0][-1*state.turns:]])
            if score > bestscore:
                bestscore = score
        
        if len(cardsbyc[1]) == 0:
            break

        nextc = cardsbyc[1][-1]
        state.next(nextc[0], nextc[1])
        if state.score > bestscore:
            bestscore = state.score

    print bestscore            
    

import argparse, os, sys
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('input_file')
    parser.add_argument('-o', '--output_file', default=None)
    args = parser.parse_args()
    if args.output_file is None:
        args.output_file = os.path.splitext(args.input_file)[0] + '.out'
    
    with open(args.output_file, 'w', 0) as outfile:
        with open(args.input_file, 'r') as infile:
            num_cases = int(infile.readline().rstrip())
            sys.stdout = outfile
            for case in range(num_cases):
                print "Case #{!s}:".format(case+1),
                solve_case(infile)
            sys.stdout = sys.__stdout__
        
