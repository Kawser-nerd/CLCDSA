def simulate(Hd, Ad, Hk, Ak, B, D, x = 0, y = 0):
    '''
    simulate the fight assuming we start with x debuffs,
    then y buffs, and finally attack, with cure only when needed
    '''
    origHd = Hd
    count = 0
    last_cure = False

    count_x = 0
    # simulate x debuffs
    while count_x < x:
        # we must cure
        if Hd - (Ak - D) <= 0:
            if last_cure == True:
                return "IMPOSSIBLE"
            last_cure = True
            #print("C")
            Hd = origHd
        else:
            last_cure = False
            #print("D")
            Ak = max(Ak - D, 0)
            count_x += 1
            
        Hd = Hd - Ak
        count += 1

    # simulate y buffs
    count_y = 0
    while count_y < y:
        if Hd - Ak <= 0:
            if last_cure == True:
                return "IMPOSSIBLE"
            last_cure = True
            #print("C")
            Hd = origHd
        else:
            #print("B")
            last_cure = False
            Ad = Ad + B
            count_y += 1
            
        Hd = Hd - Ak
        count += 1

    # attack until knight dies
    while Hk > 0:
        if Hk - Ad > 0 and Hd - Ak <= 0:
            if last_cure == True:
                return "IMPOSSIBLE"
            last_cure = True
            #print("C")
            Hd = origHd
        else:
            last_cure = False
            Hk = Hk - Ad
            #print("A", Hd, Ad, Hk, Ak)

        Hd = Hd - Ak
        count += 1
        
    return count

def check_options(Hd, Ad, Hk, Ak, B, D):
    if D == 0:
        max_x = 0
    else:
        max_x = (Ak + D - 1)//D
    if B == 0:
        max_y = 0
    else:
        max_y = (Hk - Ad) // B + 1
    best = 10**10
    for x in range(max_x+1):
        for y in range(max_y+1):
            s = simulate(Hd, Ad, Hk, Ak, B, D, x, y)
            if s != "IMPOSSIBLE":
                best = min(best, s)

    if best == 10**10:
        return "IMPOSSIBLE"
    return best


T = int(input())
for t in range(1,T+1):
    Hd, Ad, Hk, Ak, B, D = [int(x) for x in input().split()]
    print("Case #%d:"%t, check_options(Hd, Ad, Hk, Ak, B, D))
    
