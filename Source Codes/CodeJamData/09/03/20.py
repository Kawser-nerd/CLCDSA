import sys


def find_subsequences(text, pattern, modulo):
  n = len(pattern)
  locations = {}
  for char in pattern:
    locations[char] = []  
  for i, char in enumerate(text):
    try:
      locations[char].append(i)
    except KeyError:
      pass
  
  curr_counts = [1]*len(locations[pattern[0]])
  for i in range(1,len(pattern)):
    curr_char = pattern[i]
    last_char = pattern[i-1]
    last_counts = curr_counts
    curr_counts = [0]*len(locations[curr_char])
    for j in range(len(locations[curr_char])):
      for k in range(len(locations[last_char])):
        if locations[last_char][k] > locations[curr_char][j]:
          break
        else:
          curr_counts[j] += last_counts[k] % modulo
  return sum(curr_counts) % modulo
    

def main():
  if len(sys.argv) < 2:
    infile = sys.stdin
  else:
    infile = open(sys.argv[1], 'r')
  
  outfile = sys.stdout
  
  pattern = 'welcome to code jam'
  modulo = 10000
  
  num_cases = int(infile.readline().strip())
  for case in range(num_cases):
    text = infile.readline().strip()
    matches = find_subsequences(text, pattern, modulo)
    outfile.write('Case #%d: %04d\n' % (case+1, matches))


if __name__ == '__main__':
  main()