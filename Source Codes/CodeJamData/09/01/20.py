import sys

class Node:
  def __init__(self, chars):
    self.passes = []
    self.passes.extend(chars)
    
  def can_pass(self, char):
    if char in self.passes:
      return True
    else:
      return False

class Matcher:
  def __init__(self, pattern):
    self.nodes = []
    index = 0
    while index < len(pattern):
      if pattern[index] == '(':
        index += 1
        bits = []
        while pattern[index] != ')':
          bits.append(pattern[index])
          index += 1
        self.nodes.append(Node(bits))
      else:
        self.nodes.append(Node([pattern[index]]))
      index += 1
  
  def is_match(self, word):
    for i in range(len(word)):
      if not self.nodes[i].can_pass(word[i]):
        return False
    return True 
        

def match_pattern(pattern, words):
  matcher = Matcher(pattern)
  matches = 0
  for word in words:
    if matcher.is_match(word):
      matches += 1
  return matches   


def main():
  if len(sys.argv) < 2:
    infile = sys.stdin
  else:
    infile = open(sys.argv[1], 'r')
    
  outfile = sys.stdout
  
  word_length,num_words,num_cases = [int(x) for x in infile.readline().strip().split()]
  words = []
  for i in range(num_words):
    words.append(infile.readline().strip())
  
  for case in range(num_cases):
    pattern = infile.readline().strip()
    num = match_pattern(pattern, words)
    outfile.write('Case #%d: %d\n' % (case+1, num))


if __name__ == '__main__':
  main()