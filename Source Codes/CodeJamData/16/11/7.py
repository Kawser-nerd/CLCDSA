import sys

T = int(sys.stdin.readline())

for testcase in range(T):
  print "Case #{}:".format(testcase+1),
  word = sys.stdin.readline().strip()
  n = len(word)
  newword = ""
  used = [False for i in range(n)]
  
  end = n
  while end > 0:
    letter = "-"
    pos = end
    for i in range(end):
      if word[end - 1 - i] > letter:
        letter = word[end - 1 - i]
        pos = end - 1 - i
    newword = newword + letter
    end = pos
    used[pos] = True
  for i in range(n):
    if not used[i]:
      newword = newword + word[i]
  print newword