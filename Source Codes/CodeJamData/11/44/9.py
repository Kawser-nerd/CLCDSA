import copy

infile = open('D-small-attempt0.in').readlines()
infile = [line.strip() for line in infile]
wfile = open('result', 'w')
T = int(infile[0])
infile = infile[1:]

for case_no in range(1, T+1):
    line = infile[0]
    infile = infile[1:]
    P, W = [int(x) for x in line.split()]
    line = infile[0]
    infile = infile[1:]
    stars = {}
    for i in range(P):
        stars[i] = set()
    for tmp in line.split():
        a, b = [int(x) for x in tmp.split(',')]
        stars[a].add(b)
        stars[b].add(a)
        
    if 1 in stars[0]:
        wfile.write('Case #%s: 0 %s\n' % (case_no, len(stars[0])))
        continue
    
    todo = []
    route = [0]
    for s in stars[0]:
        tmp = copy.copy(route)
        tmp.append(s)
        todo.append(tmp)
    find = False
    maxth = 0
    n = [len(stars[0])]
    rlen = P
    while todo:
        route = todo[0]
        if len(route) > rlen + 1:
            todo.pop(0)
            continue
        todo.pop(0)
        current = route[-1]
        #n[0] -= 1
        if 1 in stars[current]:
            find = True
            #route.append(current)
            tmp = set()
            rlen = len(route) - 1
            for s in route:
                tmp.update(stars[s])
            tmp.difference_update(set(route))
            maxth = max(maxth, len(tmp))
        else:
            if find:
                pass
            else:
                tmpn = 0
                for s in stars[current]:
                    if s not in route:
                        tmp = copy.copy(route)
                        tmp.append(s)
                        todo.append(tmp)
                        tmpn += 1
                        n.append(tmpn)
                        
        #todo.pop()
        #if n[0] == 0:
            #n.pop(0)
            #route.pop()
            
    wfile.write('Case #%s: %s %s\n' % (case_no, rlen, maxth))
             
                        
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
    
    