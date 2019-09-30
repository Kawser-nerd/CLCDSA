def Dijkstra(N, M, Tide, Ceil, Floor):
   height = Tide;
   Best = [];
   for i in range(N):
      Best.append( [9e9]*M );

   TODO = [ [0,0] ];
   Best[0][0] = 0;
   Start = [ [0,0] ];
   # Start in 0,0.  Now find available starting positions.
   while len(Start) != 0:
      [x0, y0] = Start.pop(0);
      for dx in [-1, 0, 1]:
         for dy in [-1, 0, 1]:
            if abs(dx)+abs(dy) == 1:
               x1 = x0+dx;
               y1 = y0+dy
               if (N > x1 >= 0) and (M > y1 >= 0):
                  if Ceil[x1][y1] >= 50+Floor[x1][y1]:      # Square is allowed
                     if Ceil[x1][y1] >= 50+Floor[x0][y0]:   # Celing is not too low
                        if Ceil[x1][y1] >= 50+Tide:         # Ceiling above the tide
                           if Ceil[x0][y0] >= 50+Floor[x1][y1]:
                              if [x1, y1] not in TODO:
                                 Start.append( [x1, y1] );
                                 TODO.append ( [x1, y1] );
                                 Best[x1][y1] = 0;
                     
#   print TODO, Start


   # Now run the Dijkstra again, finding the minimum time for entering every block:

   counter = 0;
   while len(TODO) != 0:
      [x0, y0] = TODO.pop(0);
      Level = Tide - Best[x0][y0];  # Level of the water at time of reaching (x0, y0)
      if Level-Floor[x0][y0] >= 20:
         dT = 10;
      else:
         dT = 100;         # Time measured in tenth's of seconds.

      for dx in [-1, 0, 1]:
         for dy in [-1, 0, 1]:
            if Level-Floor[x0][y0] >= 20:
               dT = 10;
            else:
               dT = 100;         # Time measured in tenth's of seconds.

            
            if abs(dx)+abs(dy) == 1:
               x1 = x0+dx;
               y1 = y0+dy
               if (N > x1 >= 0) and (M > y1 >= 0):                   # A legal grid square
                  if Best[x1][y1] > Best[x0][y0] + dT:
#                     print 'Trying to get to ',(x1,y1),'from',(x0,y0)
                     
                     if Ceil[x1][y1] >= 50+Floor[x1][y1]:            # Square is allowed
                        if Ceil[x1][y1] >= 50+Floor[x0][y0]:         # Celing is not too low
                           if Ceil[x0][y0] >= 50+Floor[x1][y1]:      # Technically allowed to move

                              if Ceil[x1][y1] >= 50+Level:           # Can move to this square now
                                 if Best[x1][y1] >= Best[x0][y0] + dT:
                                    Best[x1][y1] = Best[x0][y0] + dT
                                    if [x1, y1] not in TODO:
                                       TODO.append( [x1,y1] );
                                 else:
                                    print 'weird'
                              else:
                                 # Have to wait a bit...
                                 Wait = Level - min(Ceil[x1][y1], Ceil[x0][y0]) + 50;
                                 if Level-Wait - Floor[x0][y0] < 20:
                                    dT = 100;                        # Have to then drag it
                                 if Best[x1][y1] >= Best[x0][y0] + Wait + dT:
                                    Best[x1][y1] = Best[x0][y0] + Wait + dT;
                                    if [x1, y1] not in TODO:
                                       TODO.append( [x1, y1] );

   print Best[N-1][M-1] / 10.
   return Best

   
   

T = int(raw_input());
for i in range(T):
   print "Case #%d:" % (i+1),;
   [Tide, N, M] = map(int, raw_input().split());
   Ceil = [];
   Floor = []
   for j in range(N):
      Ceil.append( map(int, raw_input().split() ) );
   for j in range(N):
      Floor.append( map(int, raw_input().split()) );

   Dijkstra( N, M, Tide, Ceil, Floor );
