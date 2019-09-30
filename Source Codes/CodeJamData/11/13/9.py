import sys
import math

hand = []
deck = []
turns = 0

def score(hand, deck, turns, debug):
	score = 0
	
	while turns > 0:
		i = chooseCard(hand, deck, turns)
		if debug == 1:
			print hand[i]
		hand, deck, turns, cardScore = playCard(hand, deck, turns, i)
		score += cardScore
				
	return score

def playCard(hand, deck, turns, i):
	turns -= 1
	
	if len(hand) <= i:
		return hand, deck, turns, 0
		
	card = hand[i]
	c = int(card[0])
	s = int(card[1])
	t = int(card[2])
	
	for j in range(0, c):
		if len(deck) > 0:
			drawCard = deck[0]
			hand.append(drawCard)
			del deck[0]
	
	del hand[i]
	turns += t
	
	return hand, deck, turns, s
	
def chooseCard(hand, deck, turns):
	if len(hand) == 0:
		return 0
	
	# if enough turns to play all cards
	if turns >= (len(hand) + len(deck)):
		return 0
		
	# play any card to gives more turns
	for i in range(len(hand)):
		card = hand[i]
		if int(hand[i][2]) > 0:
			return i
	
	# if only 1 turn left or no cards in deck, play max scoring card
	if turns == 1 or len(deck) == 0:
		maxScore = 0
		keep = 0
		for i in range(len(hand)):
			if int(hand[i][1]) > maxScore:
				maxScore = int(hand[i][1])
				keep = i
		return keep
		
	# recurse, limited to best card for each c
	
	
	bestC = []
	scoreC = []
	for i in range(len(hand)):
		c = int(hand[i][0])
		s = int(hand[i][1])
		while len(bestC) <= c:
			bestC.append(0)
			scoreC.append(0)
		
		if s > scoreC[c]:
			bestC[c] = i
			scoreC[c] = s
		
	keep = 0
	maxScore = 0
	for i in bestC:
		rHand = hand[:]
		rDeck = deck[:]
		rTurns = turns
		
		tHand, tDeck, tTurns, cardScore = playCard(rHand, rDeck, rTurns, i)
		cardScore += score(tHand, tDeck, tTurns, 0)
		if cardScore > maxScore:
			maxScore = cardScore
			keep = i
	return keep
		
if (len(sys.argv) > 1):
	out = ((len(sys.argv) > 2) and sys.argv[2]) or "test.out"
	
	fileIn = open(sys.argv[1], "r")
	fileOut = open(out, "w")
	
	fileIn.readline()
	line1 = fileIn.readline().strip()
	caseNum = 0
	while line1 != "":
		caseNum += 1
		
		for i in range(int(line1)):
			hand.append(fileIn.readline().strip().split(" "))
		
		numDeck = fileIn.readline().strip()
		for i in range(int(numDeck)):
			deck.append(fileIn.readline().strip().split(" "))

		answer = score(hand, deck, 1, 0)
		del hand[:]
		del deck[:]
		
		outstr = "Case #" + str(caseNum) + ": " + str(answer)
		print outstr
		fileOut.write(outstr + "\n")
		
		line1 = fileIn.readline()
	
	fileIn.close()
	fileOut.close()