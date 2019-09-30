infile = open('1actest1.txt')
num_cases = readint()
for iter in range(num_cases):
  cards = []
  n = readint()
  for i in range(n):
    cards = cards + [tuple([int(float(x)) for x in infile.readline().split()])]
  m = readint()
  for i in range(m):
    cards = cards + [tuple([int(float(x)) for x in infile.readline().split()])]
  s = f1ac(cards, n, m)
  print "Case #" + str(iter+1) + ": " + str(s)

def f1ac(cards, n, m):
  # First play every card with t>0
  score = 0
  hand = [True]*len(n+m)
  turns = 1
  i = 0
  while i < n:
    if hand[i] and cards[i][2] > 0:
      hand[i] = False
      score = score + cards[i][1]
      n = n + cards[i][0]
      turns = turns + cards[i][2] - 1
  print hand
  print turns
  return score