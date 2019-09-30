N, D = map( int, input().split() )
d = list( map( int, input().split() ) )
Q = int( input() )
q = list( map( lambda x: int( x ) - 1, input().split() ) )

dis = [ 0 for i in range( N + 1 ) ]
dis[ 0 ] = D
for i in range( N ):
  dis[ i + 1 ] = min( dis[ i ], abs( dis[ i ] - d[ i ] ) )

dp = [ 0 for i in range( N + 1 ) ]
dp[ N ] = 1
for i in range( N - 1, -1, -1 ):
  if dp[ i + 1 ] <= d[ i ] // 2:
    dp[ i ] = dp[ i + 1 ]
  else:
    dp[ i ] = dp[ i + 1 ] + d[ i ]

for qi in range( Q ):
  print( [ "NO", "YES" ][ dis[ q[ qi ] ] >= dp[ q[ qi ] + 1 ] ] )