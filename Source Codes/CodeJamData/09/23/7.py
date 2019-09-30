import sys

def diffs(map, r, c):   # sign cell
  ret = []
  if map[r][c] == "+":
    sign = 1
  else:
    sign = -1
    
  for dir in [ (0,+1),(0,-1),(+1,0),(-1,0) ]:
    try:
      rp = r + dir[0]
      cp = c + dir[1]
      if rp < 0 or cp < 0:
        continue
      ret.append( (int(map[rp][cp]) * sign, rp, cp, map[r][c]+map[rp][cp] ) )
    except IndexError:
      pass
  return ret

def compare(path1, path2):
  if len(path1) == len(path2):
    return path1 > path2
  else:
    return len(path1) > len(path2)

def augment(pathMap, diffMap, R, C):
  newPathMap = [ [ None for x in range(C) ] for y in range(R) ]
  for r in range(R):
    for c in range(C):
      if pathMap[r][c] is None:
        newPathMap[r][c] = None
      else:
        newPathMap[r][c] = dict( pathMap[r][c] )
  
  for r in range(R):
    for c in range(C):
      if pathMap[r][c] is None:
        continue
      
      for item in pathMap[r][c].items():
        val = item[0]
        path = item[1]
        for dir in [ (0,+1),(0,-1),(+1,0),(-1,0) ]:
          rp = r + dir[0]
          cp = c + dir[1]
          if rp < 0 or cp < 0 or rp >= R or cp >= C:
            continue
          
          for diff in diffMap[rp][cp]:
            newval = val + diff[0]
            newpath = path + diff[3]
            if newPathMap[ diff[1] ][ diff[2] ].has_key(newval) :
              if newPathMap[ diff[1] ][ diff[2] ][newval] > newpath:
                newPathMap[ diff[1] ][ diff[2] ][newval] = newpath
            else:
              newPathMap[ diff[1] ][ diff[2] ][ newval ] = newpath
  return newPathMap

def solve(map, targets):
  R = len(map)
  C = len(map[0])
  
  ret = [None] * len(targets)
  remains = [ (i, targets[i]) for i in range( len(targets) ) ]
  
  pathMap = [ [ None for x in range(C) ] for y in range(R) ]
  diffMap = [ [ None for x in range(C) ] for y in range(R) ]
  
  for r in range(R):
    for c in range(C):
      if "0" <= map[r][c] and map[r][c] <= "9":
        pathMap[r][c] = {}
        pathMap[r][c][ int(map[r][c]) ] = map[r][c]
      else:
        diffMap[r][c] = diffs(map, r, c)
  
  while len(remains) > 0:
    print remains
    deleted = []
    for r in range(R):
      for c in range(C):

        for target in remains:
          if pathMap[r][c] is not None and pathMap[r][c].has_key( target[1] ):
            if ret[ target[0] ] is None:
              ret[ target[0] ] = pathMap[r][c][ target[1] ]
              deleted.append( target )
            elif ret[ target[0] ] > pathMap[r][c][ target[1] ]:
              ret[ target[0] ] = pathMap[r][c][ target[1] ]
        
        # end for
      # end for
    # end for
    for delete in deleted:
      remains.remove(delete)
    
    pathMap = augment(pathMap, diffMap, R, C)
  # end while
  
  return ret

if __name__ == "__main__":
  infile = open( sys.argv[1], "r" )
  outfile = open( "resultC.out", "w" )
  
  N = int( infile.readline().strip() )
  for case in range(N):
    input = infile.readline().strip().split(" ")
    R = int( input[0].strip() )
    
    map = []
    for r in range(R):
      map.append( infile.readline().strip() )
    
    input = infile.readline().strip().split(" ")
    targets = [ int(tt.strip()) for tt in input ]
    
    solutions = solve( map, targets )
    
    outfile.write( "Case #%d:\n" %(case+1))
    for sol in solutions:
      outfile.write( "%s\n" % sol )
      
  infile.close()
  outfile.close()


