import sys

#s = open( 'universe-A-small-attempt1.in' )
s = open( 'universe-A-large.in' )
#s = open( 'universe.in' )
test_count = int( s.readline() )

for test_current in xrange(1, test_count+1):
  # read engine count
  engine_count = int( s.readline() )
  engines = set()
  for engine_current in xrange(0, engine_count):
    engines.add( s.readline().strip() )
  sequence_count = int( s.readline() )
  sequence = list()
  for sequence_current in xrange(0, sequence_count):
    sequence.append( s.readline().strip() )
  # process
  pos = 0
  switch_count = 0
  current_engine = ''
  while pos < sequence_count:
    candidates = engines.copy()
    while len( candidates ) > 0 and pos < sequence_count:
      #print "removing %s from " % sequence[ pos ], candidates
      candidates.discard( sequence[ pos ] )
      if len( candidates ) == 0:
        # switch
        switch_count += 1
        #print "switch to %s at %i" % ( sequence[pos], pos )
      else:
        pos += 1
  # finished test
  print "Case #%i: %i" % ( test_current, switch_count )
