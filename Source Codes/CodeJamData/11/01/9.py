infile = "A-large.in"

debug=True

def solve(inline):
    data = inline.split()
    N = int(data[0])
    assert len(data) == 1 + N*2
    turns = []
    O_list = []
    B_list = []
    
    for ix in xrange(1, len(data), 2):
        bot, pos = data[ix], int(data[ix+1])
        assert bot == "O" or bot == "B"
        turns.append(bot)
        if bot == "O": O_list.append(pos)
        if bot == "B": B_list.append(pos)

    O_pos = 1
    B_pos = 1

    t = 0
    turn_ix = 0
    next_turn = turns[0]
    O_ix, B_ix = 0, 0
    cur_O, cur_B = 1, 1
    next_O, next_B = 1, 1
    if len(O_list) > 0:
        next_O = O_list[0]
    if len(B_list) > 0:
        next_B = B_list[0]

    
    while turn_ix < len(turns):
        t += 1
        push = False
        if next_O != cur_O:
            if next_O > cur_O:
                cur_O += 1
            else:
                assert next_O < cur_O
                cur_O -= 1
        else:
            if next_turn == "O":
                push = True
                O_ix += 1
                if O_ix < len(O_list):
                    next_O = O_list[O_ix]
                
        if next_B != cur_B:
            if next_B > cur_B:
                cur_B += 1
            else:
                assert next_B < cur_B
                cur_B -= 1
        else:
            if next_turn == "B":
                push = True
                B_ix += 1
                if B_ix < len(B_list):
                    next_B = B_list[B_ix]

        if push:
            turn_ix += 1
            if turn_ix == len(turns):
                break
            next_turn = turns[turn_ix]
    return t
            
def main():
    i = file(infile)
    N = int(i.readline())
    for n in xrange(N):
        soln = solve(i.readline())
        print "Case #%d: %s" % (n+1, soln)

main()
