import sys

if (len(sys.argv) < 2):
  print("No file specified")
  sys.exit(1)
  
infile = open(sys.argv[1])
outfile = open(sys.argv[1] + ".out", "w")

num_cases = int(infile.readline().strip())

modulus = 100003

factorial = [1]

for i in range(1, 501):
  factorial.append(i * factorial[i-1])
  
def choose(n, r):
  return factorial[n] / (factorial[r] * factorial[n-r])
 
cached_results = {}

def calculate_perms(num, length):
  key = "%d-%d" % (num, length)
  if key not in cached_results:
    if length == 1:
      new_result = 1
    else:
      new_result = 0
      min_pos = max(0, 2 * length - 1 - num)
      max_pos = length - 1
      for i in range(min_pos, max_pos):
        new_result += choose(num - length - 1, length - i - 2) * calculate_perms(length, i+1)
    cached_results[key] = new_result    
  return cached_results[key]
  
for case in range(1, num_cases+1):

  n = int(infile.readline())
  
  result = 0
  
  for i in range(1, n):
    result += calculate_perms(n, i) % modulus
    
  result %= modulus
     
  outfile.write("Case #%d: %d\n" % (case, result))
  
  if case % 10 == 0:
    print("Completed case %d" % case)
    
outfile.close()
infile.close()
  
    