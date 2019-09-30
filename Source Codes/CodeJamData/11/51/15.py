from numpy import *

def AreaSum(L):
    R = 0.;
    for i in range(len(L)-1):
        R += (L[i+1][0]-L[i][0])*(L[i][1]+L[i+1][1])/2.;
    return R


def FindX(target, L):
    Eat = 0.;
    for i in range(len(L)-1):
        part = (L[i+1][0]-L[i][0])*(L[i][1]+L[i+1][1])/2.;
        if part+Eat <= target:
            Eat += part;
        else:
            todo = target - Eat;
            x0 = L[i][0];       x1 = L[i+1][0]
            y0 = L[i][1];       y1 = L[i+1][1]
#            print todo, (x0,y0), (x1,y1);
            slope = (y1-y0)/(x1-x0);
            if slope != 0:
                dx = (-y0 + sqrt(y0**2 + 2*slope*todo))/(slope)
            else:
                dx = todo/y0;
#            print dx, x0+dx
            return x0+dx;

T = int(raw_input());
for i in range(T):
    print "Case #%d:" % (i+1);
    [W, L, U, G] = map(int, raw_input().split());
    Low = [];       Lx = []
    Upp = [];       Ux = [];
    for i in range(L):
        Low.append( map(float, raw_input().split()) )
        Lx.append( Low[-1][0] );
    for i in range(U):
        Upp.append( map(float, raw_input().split()) )
        Ux.append( Upp[-1][0] );

    Lower = [];     Upper = [];     Eff = [];
    AllX = Lx+Ux;
    AllX.sort()
    for i in range(len(AllX)-2, -1, -1):
        if AllX[i] == AllX[i+1]:
            AllX.pop(i);

    li = 0;     ui = 0;
    for i in range(len(AllX)):
        x = AllX[i]
        if AllX[i] in Lx:
            Lower.append( Low[li] );
            li += 1;
        else:
            x1 = Low[li-1][0];      y1 = Low[li-1][1];
            x2 = Low[li][0];        y2 = Low[li][1]
            Lower.append( [x, y1 + (x-x1)/(x2-x1)*(y2-y1) ] );

        if AllX[i] in Ux:
            Upper.append( Upp[ui] );
            ui += 1;
        else:
            x1 = Upp[ui-1][0];      y1 = Upp[ui-1][1];
            x2 = Upp[ui][0];        y2 = Upp[ui][1]
            Upper.append( [x, y1 + (x-x1)/(x2-x1)*(y2-y1) ] );

    for i in range(len(Upper)):
        Eff.append( [Upper[i][0], Upper[i][1]-Lower[i][1]] );

#    print Lower
#    print Upper
#    print Eff

    Area = AreaSum(Eff);
    Slice = Area/G;
#    print Area
    
    for i in range(1,G):
        print FindX(Slice*i, Eff);

#    print AreaSum(Upper), AreaSum(Lower), AreaSum(Eff)



#    Walks = [];
#    ToDo = X;
#    for row in Data:
#        Walks.append( [row[1]-row[0], row[2]] );
#        ToDo -= row[1]-row[0];
#    Walks.append( [ToDo, 0] )



 
