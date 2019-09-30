""" Uri Shaked """

import sys
import time
import re

try:
    import psyco
    psyco.full()
except ImportError:
    pass

class Tee(object): 
    def __init__(self, *fds):
        self._fds = fds
    
    def write(self, data):
        for fd in self._fds:
            fd.write(data)

    def flush(self):
        for fd in self._fds:
            fd.flush()
    
    def close(self):
        for fd in self._fds:
            fd.close()

class InputReader(object):
    def __init__(self, f):
        self.f = f
    
    def readline(self):
        return self.f.readline().strip()
    
    def readnlines(self):
        entryCount = int(self.readline())
        for i in range(0, entryCount):
            yield self.readline()
        
    def readints(self):
        return list(map(int, self.readline().split(" ")))
    
    def readmatrix(self, rows, linetrans=lambda x:x):
        return [linetrans(self.readline()) for i in range(rows)]
    
    def readcases(self):
        entryCount = int(self.readline())
        for i in range(1, entryCount + 1):
            yield i

def timerWrap(func):
    def __inner(*args,**kwargs):
        start = time.time()
        try:
            return func(*args, **kwargs)
        finally:
            print >> sys.stderr, "Runtime: %.3f sec" % (time.time() - start)
    return __inner

def bestScore(hand, deck, turns):
    #print "BS", hand, deck, turns
    if turns == 0:
        return 0
    scores = 0
    newHand = []
    while len(hand) > 0:
        card = hand.pop()
        c, s, t = card
        if t > 0:
            turns += t - 1
            scores += s
            for i in range(c):
                if len(deck) > 0:
                    hand.append(deck.pop(0))
        else:
            newHand.append(card)
    hand = newHand
    if len(hand) == 0:
        return scores

    maxScoreCard = max(hand, key=lambda card: card[1])
    options = []    
    #if (maxCardsCard[0] == 0) or (maxScoreCard == maxCardsCard):
        # No more cards to take, just take max score
    #    print "ELIM", maxCardsCard, maxScoreCard
    #    return scores + optionMaxScore
    
    # We have different maxes. We need to determine if taking N
    # cards give more scores or more turns
    if maxScoreCard[0] == 0:
        tempHand = list(hand) 
        tempHand.remove(maxScoreCard)
        optionMaxScore = maxScoreCard[1] + bestScore(tempHand, list(deck), turns - 1)
        options = [optionMaxScore]
        
    cardsWithOneC = [card for card in hand if card[0] == 1]
    cardsWithTwoC = [card for card in hand if card[0] == 2]
    if len(cardsWithOneC) > 0:
        maxCard = max(cardsWithOneC, key=lambda card: card[1])
        tempHand = list(hand)
        tempHand.remove(maxCard)
        tempDeck = []
        if len(deck) > 0:
            tempDeck = deck[1:]
            tempHand.append(deck[0])
        options.append(maxCard[1] + bestScore(tempHand, tempDeck, turns - 1))
    if len(cardsWithTwoC) > 0:
        maxCard = max(cardsWithTwoC, key=lambda card: card[1])
        tempHand = list(hand)
        tempHand.remove(maxCard)
        tempDeck = []
        if len(deck) > 1:
            tempDeck = deck[2:]
            tempHand.append(deck[0], deck[1])
        elif len(deck) > 0:
            tempDeck = deck[1:]
            tempHand.append(deck[0])            
        options.append(maxCard[1] + bestScore(tempHand, tempDeck, turns - 1))
    #print options
    return scores + max(options)

def runCase(inpFile):
    hand = [map(int, x.strip().split(" ")) for x in inpFile.readnlines()]
    deck = [map(int, x.strip().split(" ")) for x in inpFile.readnlines()]
    best = bestScore(hand, deck, 1)
    print best

#@timerWrap
def main():
    inpFile = InputReader(open("pseudo.in", "r"))
    sys.stdout = Tee(sys.stdout, open("pseudo.out", "w"))
    for index in inpFile.readcases():
        print "Case #%d:" % index, 
        runCase(inpFile)
        sys.stdout.flush()

main()
