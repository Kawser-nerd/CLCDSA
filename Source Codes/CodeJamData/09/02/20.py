import sys

def read_map(infile):
  height,width = [int(x) for x in infile.readline().strip().split()]
  altitudes = []
  for i in range(height):
    row = [int(x) for x in infile.readline().strip().split()]
    altitudes.append(row)
  
  flow_map = []
  for i in range(height):
    flow_map.append([])
    for j in range(width):
      flow_map[i].append(0)
    
  # Build the flow map
  for i in range(height):
    for j in range(width):
      neighbors = []
      if i > 0:
        neighbors.append((altitudes[i-1][j], i-1, j))
      if j > 0:
        neighbors.append((altitudes[i][j-1], i, j-1))
      if i+1 < height:
        neighbors.append((altitudes[i+1][j], i+1, j))
      if j+1 < width:
        neighbors.append((altitudes[i][j+1], i, j+1))
      neighbors.sort()
      if neighbors and neighbors[0][0] < altitudes[i][j]:
        flow_map[i][j] = (neighbors[0][1], neighbors[0][2])
      else:
        flow_map[i][j] = (i, j)
      
  return flow_map


def find_basins(flow_map):
  height = len(flow_map)
  width = len(flow_map[0])
  basin_map = [ [i*width+j for j in range(width)] for i in range(height)]
  
  changed = True
  while changed:
    changed = False
    for i in range(height):
      for j in range(width):
        if basin_map[i][j] != basin_map[flow_map[i][j][0]][flow_map[i][j][1]]:
          basin_map[i][j] = basin_map[flow_map[i][j][0]][flow_map[i][j][1]]
          changed = True
  
  # Label the basins
  basins = {}
  num = 0
  for i in range(height):
    for j in range(width):
      if basin_map[i][j] not in basins:
        basins[basin_map[i][j]] = chr(ord('a') + num)
        num += 1
      basin_map[i][j] = basins[basin_map[i][j]]
  return basin_map


def print_map(map_list, outfile):
  height = len(map_list)
  for i in range(height):
    outfile.write('%s\n' % (' '.join([str(x) for x in map_list[i]])))      
      
        
def main():
  if len(sys.argv) < 2:
    infile = sys.stdin
  else:
    infile = open(sys.argv[1], 'r')
  
  outfile = sys.stdout
  
  num_cases = int(infile.readline().strip())
  for case in range(num_cases):
    flow_map = read_map(infile)
    basin_map = find_basins(flow_map)
    outfile.write('Case #%d:\n' % (case+1))
    print_map(basin_map, outfile)
  

if __name__ == '__main__':
  main()
  