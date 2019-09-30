import sys

if (len(sys.argv) < 2):
  print("No file specified")
  sys.exit(1)
  
infile = open(sys.argv[1])
outfile = open(sys.argv[1] + ".out", "w")

num_cases = int(infile.readline().strip())

def add_dir(dirs, new_dir):
  
  result = 0
  if len(new_dir) > 0:
    child_dir = new_dir[0]
    if child_dir not in dirs:
      result = 1
      dirs[child_dir] = {}
    result += add_dir(dirs[child_dir], new_dir[1:])
  return result 
    
for case in range(1, num_cases+1):

  n, m = map(int, infile.readline().split())
  
  directories = {}
  
  for i in range(n):
    dir = infile.readline().strip().split("/")[1:]
    add_dir(directories, dir)
  
  result = 0
  for i in range(m):
    dir = infile.readline().strip().split("/")[1:]
    result += add_dir(directories, dir)
 
  outfile.write("Case #%d: %d\n" % (case, result))
  
  if case % 100 == 0:
    print("Completed case %d" % case)
    
outfile.close()
infile.close()
  
    