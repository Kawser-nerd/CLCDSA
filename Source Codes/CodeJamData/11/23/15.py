import sys
from random import choice

def split_rooms(rooms, wall):
  #find the room that contaied both vertices
  #print rooms, wall
  the_room = [r for r in rooms if wall[0] in r and wall[1] in r][0]
  rooms.remove(the_room)
  def in_left(v):
    return v > wall[0] and v < wall[1]

  new_left = [v for v in the_room if in_left(v) or v in wall]
  new_right = [v for v in the_room if (not in_left(v)) or v in wall]

  rooms.append(new_left)
  rooms.append(new_right)

  return rooms

def next_color_for_room(room, vertex_colors, max_num):
  current_colors = set([vertex_colors[v] for v in room])
  possibilities = []
  for x in xrange(1, max_num + 1):
    if x not in current_colors:
      possibilities.append(x)

  if len(possibilities) == 0:
    return 0# no need to color this vertex quite yet
  else:
    return choice(possibilities)    

def solve_case(case_num, line_1, line_2, line_3):
  num_vertices, num_walls = map(lambda x: int(x.strip()), line_1.split(" "))
  walls = zip(line_2.strip().split(" "), line_3.strip().split(" "))
  walls = map(lambda x: (int(x[0]), int(x[1])), walls)
  rooms = [range(1, num_vertices + 1)] # start with one room
  for wall in walls:
    #every wall splits exactly one room in two
    rooms = split_rooms(rooms, wall)
  #print rooms
  num_colors = min(map(len, rooms)) #assumption - go greedy
  #map colors
  #TOTAL HACK: keep trying until solution is acceptable
  while True:
    vertex_colors = dict([(r+1, 0) for r in range(num_vertices)])
    for room in rooms:
      for vertex in room:
        if vertex_colors[vertex] == 0: #need to color!
          #grant next available color
          vertex_colors[vertex] = next_color_for_room(
                                    room, vertex_colors, num_colors)
   
    #did anything not get labeled? label it now
    for key in vertex_colors:
      if vertex_colors[key] == 0:
        vertex_colors[key] = 1

    def all_rooms_happy():
      for room in rooms:
        current_colors = set([vertex_colors[v] for v in room])
        for color in range(num_colors):
          if not color + 1 in current_colors:
            return False  
      return True

    if all_rooms_happy():
      break;

  print "Case #%d: %d" % (c, num_colors)

  result = []
  for v in range(num_vertices):
    result.append(str(vertex_colors[v+1]))
  
  print " ".join(result)
  

#main
input_f = open(sys.argv[1])
num_cases = int(input_f.readline())
for c in xrange(1, num_cases+1):
  solve_case(c, input_f.readline(), input_f.readline(), input_f.readline())
