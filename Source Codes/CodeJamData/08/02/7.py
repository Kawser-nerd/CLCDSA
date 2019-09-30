import sys

def to_min( s ):
  time = s.split( ":" )
  return int( time[0] ) * 60 + int( time[1] ) 

s = open( 'B-large.in' )
test_count = int( s.readline() )

for test_current in xrange(1, test_count+1):
  # read stuff
  tt = int( s.readline() )
  counts = s.readline().strip().split( " " )
  nab_count = int( counts[0] )
  nba_count = int( counts[1] )
  # read a-b
  a = dict()
  b = dict()
  for i in xrange(-60, 24*60*60):
    a[i] = 0
    b[i] = 0
    
  for i in xrange(0, nab_count):
    times = s.readline().strip().split( " " )
    depart = to_min( times[0] )
    arrive = to_min( times[1] )
    a[ depart - tt ] = int( a[ depart - tt ] ) - 1
    b[ arrive ] = int( b[ arrive ] ) + 1
    
  for i in xrange(0, nba_count):
    times = s.readline().strip().split( " " )
    depart = to_min( times[0] )
    arrive = to_min( times[1] )
    b[ depart - tt ] = int( b[ depart - tt ] ) - 1
    a[ arrive ] = int( a[ arrive ] ) + 1
    
  # sum the deltas to get requirement
  a_min = 0
  current = 0
  for i in xrange( -60, 24*60*60 ):
    current += int( a[ i ] )
    #if a[ i ] != 0:
    #  print "a %i %i => %i" % ( i, a[ i ], current )
    if current < a_min:
      a_min = current
  
  b_min = 0
  current = 0
  for i in xrange( -60, 24*60*60 ):
    current += int( b[ i ] )
    #if b[ i ] != 0:
    #  print "b %i %i => %i" % ( i, b[ i ], current )
    if current < b_min:
      b_min = current
          
  # finished test
  print "Case #%i: %i %i" % ( test_current, -a_min, -b_min )
