from collections import deque, defaultdict

E = 0.0

def main():
  f = open('A.in', 'r')
  fout = open('A.out', 'w')
  T = int (f.readline())

  for t in range(1, T+1):
    print 'Case #' + str(t) + ':',
    r1 = int (f.readline())
    s1 = getSet(f, r1)
    r2 = int (f.readline())
    s2 = getSet(f, r2)
    res = s1 & s2
    if (len(res) == 1):
      print list(res)[0]
    elif (len(res) > 1):
      print 'Bad magician!'
    else:
      print 'Volunteer cheated!'

def getSet(f, r):
  s = set()
  for i in range(1, 4+1):
    cards = f.readline().split()
    if i == r:
      for card in cards:
        s.add(card)
  return s
  
if __name__ == "__main__":
    main()
