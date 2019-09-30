from collections import Counter

def solve(tribes):

    #for t in tribes:
    #    for k, v in t.items():
    #        print k, v

    attacks = {}
    for tribe in tribes:
        #days = [tribe['first_day'] + tribe['period'] * i + for i in range(tribe['times'])]
        #wests
        for i in range(tribe['times']):
            attack = {}
            attack['day'] = tribe['first_day'] + tribe['period'] * i
            attack['west'] = tribe['west'] + tribe['move'] * i
            attack['east'] = tribe['east'] + tribe['move'] * i
            attack['str'] = tribe['str'] + tribe['delta_str'] * i
            if attack['str'] > 0: 
                day = attack['day']
                if day not in attacks:
                    attacks[day] = []
                attacks[day].append(attack)


    #_attacks.sort(key=lambda x:x['day'])


    # cannot success for Large TODO
    wall = [0 for i in range(100000)]

    ans = 0
    for day in sorted(attacks.keys()):
        add_wall = False
        for a in attacks[day]:
            win = False
            for i in range(a['west'], a['east']):
                if wall[i] < a['str']: 
                    win = True
                    add_wall = True
                    break
            if win: 
                ans += 1 

        if add_wall:
            for a in attacks[day]:
                for i in range(a['west'], a['east']):
                    wall[i] = max(wall[i], a['str'])
                
    print ans

    return ans

if __name__ == '__main__':

    import sys
    
    input_file = sys.argv[1]
    output_file = input_file[:].replace('.in', '.out')


    f_in = open(input_file, 'r')
    f_out = open(output_file, 'w')

    T, = [int(x) for x in f_in.readline().split()]

    for case in range(1, T+1):
        print 
        print '====================='
        print '    ' + str(case)
        print '====================='

        tribes = []
        N, = [int(x) for x in f_in.readline().split()]
        for i in range(N):
            di, ni, wi, ei, si, delta_di, delta_pi, delta_si = [int(x) for x in f_in.readline().split()]
            tribe = {
                'first_day': di,
                'period': delta_di,
                'times': ni,
                'west': wi,
                'east': ei,
                'str': si,
                'delta_str': delta_si,
                'move': delta_pi,
            }
            tribes.append(tribe)
              

        # Solve
        ans = solve(tribes)

        ## Output
        f_out.write('Case #%d: %s\n' % (case, ans))

        

