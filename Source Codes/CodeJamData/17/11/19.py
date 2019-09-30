def FillRow(r):
    i = 0;
    while r[i] == '?':
        i += 1;
        if i == len(r):
            return "";
    c = r[i];
    newR = [];
    for l in r:
        if l == c or l == '?':
            newR.append(c);
        else:
            c = l;
            newR.append(c);
    return ''.join(newR);
            

def Solve(inp):
    Ans = [];
    rowi = 0;
    empty = [];
    
    for row in inp:
        Ans.append(FillRow(row));
        if (Ans[-1] == ""):
            if ((rowi-1) in empty) or (rowi == 0):
                empty.append(rowi);
            else:
                Ans[-1] = Ans[-2];
        rowi += 1;

    for index in empty:
        Ans[index]= Ans[max(empty)+1]

    for row in Ans:
        print row;

T = int(raw_input());
for q in range(T):
    [R, C] =  map(int, raw_input().split());
    data = [];
    for i in range(R):
        data.append(list(raw_input()));

    print "Case #%d:" % (q+1);
    Solve(data);
