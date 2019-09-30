import sys

iFile = open(sys.argv[1],"r")

size = int(iFile.readline().strip())

for i in range(size):

  line = iFile.readline().strip().split()
  
  N = int(line[0])
  M = int(line[1])
  K = int(line[2])
  
  stones = 0
  
  if K <= 4:
    stones = K
  elif min(N,M) <= 2 :
    stones = K
  elif min(N,M) == 3:
    enclosed = int((K - 2) / 3)
    enclosed = min(enclosed,max(N,M)-2)
    stones = K - enclosed
  else:
    if K < 8:
      enclosed = 1
    elif K < 10:
      enclosed = 2
    elif K < 12:
      enclosed = 3
    elif K < 14 or max(N,M) == 4:
      enclosed = 4
    elif K < 16:
      enclosed = 5
    else:
      enclosed = 6
    
    stones = K - enclosed
    
  
  output = str(stones)
  
  print("Case #"+str(i+1)+": "+output)
