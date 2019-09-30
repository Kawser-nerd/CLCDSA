def CheckServings(s):
    mins = min(s);
    maxs = max(s);
    if maxs / mins > 1.1/0.89:
        return False;

    v = int((mins * maxs)**0.5);

    while (v * 0.9 <= mins):
        if (v * 0.9 <= mins) and (v * 1.1 >= maxs):
            return True;
        v += 1;

    return False;
    

def Solve(N, req, data):
    Ans = 0;
    while (True):
#        print data
        Servings = [];
        for i in range(N):
            if len(data[i]) == 0:
                return Ans;
            Servings.append( (1.*data[i][0]) / (req[i]) );

        if CheckServings(Servings):
            Ans += 1;
            for i in range(N):
                data[i].pop(0);

        else:
            index = Servings.index(min(Servings));
            data[index].pop(0);
                    
T = int(raw_input());
for q in range(T):
    [N, P] =  map(int, raw_input().split());
    Ri = map(int, raw_input().split());     # Requirements

    data = [];
    for j in range(N):
        Pi = map(int, raw_input().split());
        Pi.sort();
        data.append(Pi);

    print "Case #%d:" % (q+1),;
    print Solve(N, Ri, data);
