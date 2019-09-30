#!/usr/bin/python
#coding:utf8

best_score = -1
from operator import itemgetter

def withturns(hand):
    if hand[2] > 0:
        return True
    return False
known = set()
def game_on(inhand,indeck,score, turns):
    global best_score, known
    #print "*"* 10
    #print inhand, indeck, score, turns
    if (tuple(inhand), tuple(indeck)) in known:
        return
    known.add((tuple(inhand), tuple(indeck)))
    if score > best_score:
        best_score = score
    if turns == 0:
        return
    turns -= 1

    if not inhand:
        return
    inhand.sort(key=itemgetter(2),reverse=True)
    i = 0
    card = inhand[i]
    adding = 0
    if card[0] > 0:
        adding = min(card[0], len(indeck))
    game_on(inhand[:i]+inhand[i+1:] + indeck[:adding], indeck[adding:],  score+ card[1], turns+card[2] )

    inhand.sort(key=itemgetter(1),reverse=True)
    i = 0
    card = inhand[i]
    adding = 0
    if card[0] > 0:
        adding = min(card[0], len(indeck))
    game_on(inhand[:i]+inhand[i+1:] + indeck[:adding], indeck[adding:],  score+ card[1], turns+card[2] )

    inhand.sort(key=itemgetter(0), reverse=True)
    i = 0
    card = inhand[i]
    adding = 0
    if card[0] > 0:
        adding = min(card[0], len(indeck))
    game_on(inhand[:i]+inhand[i+1:] + indeck[:adding], indeck[adding:],  score+ card[1], turns+card[2] )

    
    #print "*"* 10
if __name__ == '__main__':
    num = input()
    for casenum in range(num):
        hand = input()
        inhand = []
        for i in range(hand):
            card = map(long,raw_input().strip().split())
            inhand.append(tuple(card))
        deck = input()
        indeck = []
        for i in range(deck):
            card = map(long,raw_input().strip().split())
            indeck.append(tuple(card))
        #print inhand,indeck
        game_on(inhand,indeck, 0, 1)
        print "Case #%s: %s"% (casenum+1, best_score)
        best_score = -1
        known = set()
