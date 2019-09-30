import sys
from math import sqrt, atan2
import psyco
psyco.full()


def main():
  in_filename = sys.argv[1]
  out_filename = sys.argv[2]
  in_file = open(in_filename, 'r')
  out_file = open(out_filename, 'w')

  (t,) = get_next(in_file)

  results = []

  for step in xrange(0, t):
    (h,w,d) = get_next(in_file)
    room = get_next_room(in_file, h)
    xindex = -1
    yindex = -1
    for i in xrange(h):
      xindex = room[i].find("X")
      if xindex >= 0:
        yindex = i
        break
    h -= 2
    w -= 2
    
    distance = 1
    
    viewable = {}
    
    while True:
        prev = len(viewable)
        size = distance * 2 + 1
        if distance % 2 == 0:
            top = distance * h * -1
        else:
            top = ( ((yindex) * 2 - 1) + (distance - 1) * h) * -1
        if distance % 2 == 0:
            bottom = distance * h
        else:
            bottom = ((h - yindex) * 2 + 1) + (distance - 1) * h
        if distance % 2 == 0:
            left = distance * w * -1
        else:
            left = (((xindex) * 2 - 1) +  (distance - 1) * w) * -1
        if distance % 2 == 0:
            right = distance * w
        else:
            right = (((w - xindex) * 2 + 1) +  (distance - 1) * w)

        for i in xrange(size):
            if i % 2 == 0:
                x = i * w + left
            else:
                x = (((xindex) * 2 - 1) +  (i - 1) * w) + left
            #print distance, i , x,  sqrt(x**2 + top**2), sqrt(x**2 + bottom**2)
            if sqrt(x**2 + top**2) <= d:
                viewable[ atan2(x,top) ] = 1
            if sqrt(x**2 + bottom**2) <= d:
                viewable[ atan2(x,bottom) ] = 1
        
        x = left
        for i in xrange(1,size-1):
            if i % 2 == 0:
                y = i * h + top
            else:
                y = (((yindex) * 2 - 1) +  (i - 1) * h) + top
            #print distance, i , y, sqrt(left**2 + y**2), sqrt(right**2 + y**2)
            if sqrt(left**2 + y**2) <= d:
                viewable[ atan2(left,y) ] = 1
            if sqrt(right**2 + y**2) <= d:
                viewable[ atan2(right,y) ] = 1
        if prev == len(viewable):
            break
        distance += 1
    
    results.append(len(viewable))
    
  print_out(results, out_file)
def get_next(f):
  line = f.readline()
  line_data = line.rstrip('\n').split(' ')
  return [int(value) for value in line_data]
  
def get_next_room(f, n):
  lines = []
  for i in xrange(n):
     line = f.readline()
     line_data = line.rstrip('\n')
     lines.append(line_data)
  return lines
  
def print_out(results, out_file):
  for i, result in enumerate(results):
    num = i + 1
    print >>out_file, "Case #%d: %s" % (num, result)
    #print  "Case #%d: %s" % (num, result)

if __name__ == '__main__':
  main()
