from numpy import *

def BladeCheck(size):
    for r1 in range(R-size+1):
        for c1 in range(C-size+1):     # Start in position (r1, c1)

            x = r1+1;
            y = c1+1;
            z = size-1;


            RowVal = MR[r1+size][c1+size]+MR[r1][c1]-MR[r1+size][c1]-MR[r1][c1+size]
            ColVal = MC[r1+size][c1+size]+MC[r1][c1]-MC[r1+size][c1]-MC[r1][c1+size]

            RowVal -= Mass[x][y]*y + Mass[x+z][y+z]*(y+z) + Mass[x][y+z]*(y+z) + Mass[x+z][y]*y;
            ColVal -= Mass[x][y]*x + Mass[x+z][y+z]*(x+z) + Mass[x][y+z]*x + Mass[x+z][y]*(x+z);

            m = MSum[r1][c1] + MSum[r1+size][c1+size]-MSum[r1][c1+size]-MSum[r1+size][c1];
            m -= Mass[x][y] + Mass[x+z][y] + Mass[x][y+z] + Mass[x+z][y+z]

            if (2* RowVal == m * (size+2*c1+1)):
                if 2* ColVal == m * (size+2*r1+1):
                    return True;
    return False;


T = int(raw_input());
for i in range(T):
    print "Case #%d:" % (i+1),;
    [R,C,D] = map(int, raw_input().split());
    Mass = [[0]*(C+1)];
    for i in range(R):
        Mass.append([0]);
        line = raw_input().split();
        for c in line[0]:
            Mass[i+1].append(int(c));

    MR = [];    MC = [];            # Mass of rows/columns
    MSum = [];
    for i in range(R+1):
        MR.append([0]*(C+1));
        MC.append([0]*(C+1));
        MSum.append( [0]*(C+1) );

    for i in range(1,R+1):
        for j in range(1,C+1):
            MR[i][j] = MR[i-1][j] + MR[i][j-1] - MR[i-1][j-1] + Mass[i][j]*j
            MC[i][j] = MC[i-1][j] + MC[i][j-1] - MC[i-1][j-1] + Mass[i][j]*i
            MSum[i][j] = MSum[i-1][j] + MSum[i][j-1] - MSum[i-1][j-1] + Mass[i][j]
            

    BIG = min(R,C);
    Match = False;
    Case = BIG+1;
    while (Case > 3) and not Match:
        Case -= 1;
        Match = BladeCheck(Case);
        

    if Match:
        print Case;
    else:
        print "IMPOSSIBLE"


