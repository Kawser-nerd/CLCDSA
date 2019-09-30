def TryPath(c0):
    direction = 'd';
    r = 0;
    c = c0;
    PATH = [ (r, c) ];

    if H==1:
        Map[r][c] = 8;
        return 1;

    if Map[r+1][c] != 0:
        Map[r][c] = 8;
        return 0;
        

    while (True):
        lost = True;
        next = ' ' ;

        if direction == 'd':
            r += 1;
            if (c != 0) and (Map[r][c-1] == 0):
                next = 'l';
            elif (r != H-1) and (Map[r+1][c] == 0):
                next = 'd';
            elif (c != W-1) and (Map[r][c+1] == 0):
                next = 'r';
            else:
                next = 'u';

        if direction == 'l':
            c -= 1;
            if (r != 0) and (Map[r-1][c] == 0):
                next = 'u';
            elif (c != 0) and (Map[r][c-1] == 0):
                next = 'l';
            elif (r != H-1) and (Map[r+1][c] == 0):
                next = 'd';
            else:
                next = 'r';

        if direction == 'u':
            r -= 1;
            if (c != W-1) and (Map[r][c+1] == 0):
                next = 'r';
            elif (r != 0) and (Map[r-1][c] == 0):
                next = 'u';
            elif (c != 0) and (Map[r][c-1] == 0):
                next = 'l';
            else:
                next = 'd';

        if direction == 'r':
            c += 1;
            if (r != H-1) and (Map[r+1][c] == 0):
                next = 'd';
            elif (c != W-1) and (Map[r][c+1] == 0):
                next = 'r';
            elif (r != 0) and (Map[r-1][c] == 0):
                next = 'u';
            else:
                next = 'l';

        PATH.append( (r,c) );
        direction = next;

        if r == H-1:
            for pair in PATH:
                Map[pair[0]][pair[1]] = 8;
            return 1;

        if (r == 0) and (c == c0) and (direction == 'd'):
            for pair in PATH:
                Map[pair[0]][pair[1]] = 8;
            return 0;


def Show(MAP):
    print "\n";
    for row in MAP:
        print row;

T = int(raw_input());
for q in range(T):
    print "Case #%d:" % (q+1),;

    [W,H,B] = map(int, raw_input().split());
    Map = [];
    for i in range(H):
        Map.append([0]*W);
    for i in range(B):
        [x0, y0, x1, y1] = map(int, raw_input().split());
        for c in range(x0, x1+1):
            for r in range(y0, y1+1):
                Map[r][c] = 1;

    Paths = 0;
    for i in range(W):
        if Map[0][i] == 0:
            Paths += TryPath(i);
    print Paths

    
