IMP = 'IMPOSSIBLE'

def solvePrimary(R, Y, B):
    if R >= Y and R >= B:
        if 2 * R > R + Y + B:
            return IMP
        ret = ['RYB'] * (Y+B-R) + ['RY'] * (R-B) + ['RB'] * (R-Y)
    elif Y >= R and Y >= B:
        if 2 * Y > R + Y + B:
            return IMP
        ret = ['YRB'] * (R+B-Y) + ['YR'] * (Y-B) + ['YB'] * (Y-R)
    else:
        if 2 * B > R + Y + B:
            return IMP
        ret = ['BRY'] * (R+Y-B) + ['BR'] * (B-Y) + ['BY'] * (B-R)
    ret = ''.join(ret)
    return ret
    
def solveFull(R, O, Y, G, B, V):
    if R == G and O == Y == B == V == 0:
        return 'RG' * R
    if Y == V and R == O == G == B == 0:
        return 'YV' * Y
    if B == O and R == Y == G == V == 0:
        return 'BO' * B

    if G > 0 and R-G <= 0:
        return IMP
    if V > 0 and Y-V <= 0:
        return IMP
    if O > 0 and B-O <= 0:
        return IMP
    
    ret = solvePrimary(R-G, Y-V, B-O)
    
    if ret == IMP:
        return IMP
    
    if G > 0:
        i = ret.find('R')
        ret = ret[:i] + 'RG' * G + ret[i:]    
    if V > 0:
        i = ret.find('Y')
        ret = ret[:i] + 'YV' * V + ret[i:]    
    if O > 0:
        i = ret.find('B')
        ret = ret[:i] + 'BO' * O + ret[i:]
        
    return ret

IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

NUM_TESTS = int(IN.readline())

for test in xrange(NUM_TESTS):
    N, R, O, Y, G, B, V = map(int,IN.readline().split())
    answer = solveFull(R, O, Y, G, B, V)
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print test+1, answer

IN.close()
OUT.close()
