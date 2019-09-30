import sys

if (len(sys.argv) < 2):
  print("No file specified")
  sys.exit(1)
  
infile = open(sys.argv[1])
outfile = open(sys.argv[1] + ".out", "w")

num_cases = int(infile.readline().strip())

for case in range(1, num_cases+1):
  n, k, b, t = map(int, infile.readline().split())
  
  positions = map(int, infile.readline().split())
  speeds = map(int, infile.readline().split())
  
  positions.reverse()
  speeds.reverse()
  
  swaps = 0
  
  chick_idx = 0
  found_completers = 0
  
  while chick_idx < n and found_completers < k:
    if speeds[chick_idx] * t >= (b - positions[chick_idx]):
      swaps += chick_idx - found_completers
      found_completers += 1
    chick_idx += 1
      
  if found_completers < k:
    result = "IMPOSSIBLE"
  else:
    result = "%d" % swaps
    
  outfile.write("Case #%d: %s\n" % (case, result))
  
  if case % 100 == 0:
    print("Completed case %d" % case)
    
outfile.close()
infile.close()
  
    