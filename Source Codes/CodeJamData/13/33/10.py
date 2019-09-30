T = int(raw_input())

for t in range(T):
    N = int(raw_input().strip())
    
    res = 0
    WALL = { }
    attacks = [ ]
    for n in range(N):
        di, ni, wi, ei, si, delta_di, delta_pi, delta_si = [int(i) for i in raw_input().split()]
        for _ in range(ni): # generate data of that attack, add to list of all attacks
            attacks.append([di, wi, ei, si])
            
            # data for next attack
            di += delta_di
            wi += delta_pi
            ei += delta_pi
            si += delta_si
    
    # sort attack by day
    attacks = sorted(attacks, key=lambda x: x[0])
    
    prev_day = -1
    idx = 0
    success_attacks = [ ]
    while idx < len(attacks):
        di, wi, ei, si = attacks[idx]
        if di != prev_day:
            # build wall
            for d_idx in success_attacks: 
                 ddi, dwi, dei, dsi = attacks[d_idx] # damaged segment
                 
                 for didx in xrange(dwi, dei):
                    if WALL.get(didx, 0) < dsi:
                        WALL[didx] = dsi
            
            del success_attacks[:]
        
        flag = False    
        for i in xrange(wi, ei):
            hi = WALL.get(i, 0)
            if si > hi:
                flag = True
                break
        
        if flag:
            res += 1
            success_attacks.append(idx)   
        
        prev_day = di
        idx += 1
    
    print 'Case #%s: %s' % (t+1, res)