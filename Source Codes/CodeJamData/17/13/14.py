def GetHits(attack, total, buff):
    base = (total-1)/attack + 1;
    if buff == 0:
        return base;
    for i in range(1, total/buff+1):
        base = min(base, (total-1)/(attack + i*buff) + 1 + i);
    return base;    



def RunGame(Hd, Ak, D, debuffsApplied, hitsRequired):
    time = 0;
    debuffs = 0;
    hits = 0;
    health = Hd;
    attack = Ak;

    while (hits < hitsRequired and (time < 1000)):
        if (debuffs < debuffsApplied):
            if (attack - D >= health):
                health = Hd;
            else:
                attack -= D;
                debuffs += 1;
        else:
            if (hits + 1 == hitsRequired) or (attack < health):
                hits += 1;
            else:
                health = Hd;

        health -= attack;
        time += 1;
            
    return time;


def Solve(Hd, Ad, Hk, Ak, B, D):
    MinHits = GetHits(Ad, Hk, B);
    MaxDebuffs = 0;
    if (D > 0):
        MaxDebuffs = (Ak-1) / D + 1;

    result = [];
    for i in range(Ak+1):
        result.append( RunGame(Hd, Ak, D, i, MinHits) );
        
    #print result;

    if min(result) == 1000:
        return "IMPOSSIBLE";
    return min(result);

                    
T = int(raw_input());
for q in range(T):
    [Hd, Ad, Hk, Ak, B, D] =  map(int, raw_input().split());

    print "Case #%d:" % (q+1),;
    print Solve(Hd, Ad, Hk, Ak, B, D);    
    #print (Hd, Ad), (Hk, Ak)
