from numpy import *

def Sort(WalkList):
    V = [];
    Ret = [];
    for pair in WalkList:
        V.append(pair[1]);

    V.sort()

    while len(WalkList) > 0:
        for row in WalkList:
            if row[1] == V[0]:
                V.pop(0);
                Ret.append( row );
                WalkList.remove(row);
    return Ret


T = int(raw_input());
for i in range(T):
    print "Case #%d:" % (i+1),;
    [X, S, R, t, N] = map(float,  raw_input().split());
    N = int(N)
    Data = [map(float, raw_input().split()) for i in range(N)];

    Walks = [];
    ToDo = X;
    for row in Data:
        Walks.append( [row[1]-row[0], row[2]] );
        ToDo -= row[1]-row[0];
    Walks.append( [ToDo, 0] )
    SWalks = Sort(Walks);

#    print SWalks,
#    print t, (S,R)
    Time = 0.;      CanRun = t+0.;
    
    for row in SWalks:
        t0 = row[0]/(R+row[1]+0.);
#        print row, Time, t0, CanRun
        if t0 <= CanRun:
            Time += t0;
            CanRun -= t0;
        else:
            d1 = (CanRun)*(row[1]+R);
            d2 = row[0]-d1;
            Time += CanRun + d2/(S+row[1]);
            CanRun = 0;

    print "%6.8f" % Time


 
