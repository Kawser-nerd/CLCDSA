import sys
import math

#s = open( 'C-small-attempt0.in' )
s = open( 'C-large.in' )
#s = open( 'racquet.in' )
test_count = int( s.readline() )

def a( r ):
  return math.pi * r * r

def a_slice( x, t, r ):
  return a_chord( x, r ) - a_chord( x + t, r )

def a_chord( x, r ):
  #print "a_chord x %f r %f" % ( x, r )
  return r * r * math.acos( x / r ) - x * math.sqrt( r*r - x*x )

def dist( x, y ):
  return math.sqrt( x*x + y*y )

def a_pie( x, y, r ):
  return 
  
for test_current in xrange(1, test_count+1):
  data = s.readline().strip().split( " " )
  f = float( data[0] ) # fly radius
  R = float( data[1] ) # big radius
  t = float( data[2] ) # ring thickness
  r = float( data[3] ) # string radius
  g = float( data[4] ) # string gap
  #print "f %f R %f t %f r %f g %f" % ( f, R, t, r, g )
  
  real_little_r = R - t - f
  real_string = r + f
  real_gap = g - 2*f
  
  if real_gap <= 0 or real_little_r <= 0:
    prob = 1
  else:
    total = a( R )
    
    # add up all the boxes in one quarter
    pos_y = real_string
    boxes = 0
    while pos_y < real_little_r:
      pos_x = real_string
      while pos_x < real_little_r:
        x_dist = math.sqrt( real_little_r * real_little_r - pos_y * pos_y ) - pos_x
        y_dist = math.sqrt( real_little_r * real_little_r - pos_x * pos_x ) - pos_y
        if x_dist > 0 and y_dist > 0: # both on the circle
          #print "xdist %f ydist %f posx %f posy %f gap %f r %f" % ( x_dist, y_dist, pos_x, pos_y, real_gap, real_little_r )
          if x_dist > real_gap:
            if y_dist > real_gap:
              if dist(pos_x + real_gap, pos_y + real_gap ) < real_little_r:
                # normal box
                box = real_gap * real_gap
              else:
                # get the whole corner
                box = ( a_slice(pos_x, x_dist, real_little_r) - ( x_dist * 2*pos_y ) ) / 2
                # find out the 2 occlusions
                ox = pos_x + real_gap
                oxdist = math.sqrt( real_little_r * real_little_r - pos_y * pos_y ) - ox
                o1 = ( a_slice(ox, oxdist, real_little_r) - ( oxdist * 2*pos_y ) ) / 2
                oy = pos_y + real_gap
                oydist = math.sqrt( real_little_r * real_little_r - pos_x * pos_x ) - oy
                o2 = ( a_slice(oy, oydist, real_little_r) - ( oydist * 2*pos_x ) ) / 2
                box = box - o1 - o2
            else:
              # x ok, y not ok
              box = ( a_slice(pos_x, real_gap, real_little_r) - ( real_gap * 2*pos_y ) ) / 2
          else:
            # x not ok
            if y_dist > real_gap:
              # x not ok, y ok
              box = ( a_slice(pos_y, real_gap, real_little_r) - ( real_gap * 2*pos_x ) ) / 2
            else:
              # x, y both less than real gap
              # only go as far as x_dist
              box = ( a_slice(pos_x, x_dist, real_little_r) - ( x_dist * 2*pos_y ) ) / 2
          
          #print "box %f" % box      
          boxes += box
        pos_x += real_gap + 2 * real_string
      pos_y += real_gap + 2 * real_string

    prob = 1 - ( boxes * 4 ) / total
    #print "total %f ring %f boxes %f" % ( total, total-a(real_little_r), boxes * 4)
  # finished test
  print "Case #%i: %f" % ( test_current, prob )
