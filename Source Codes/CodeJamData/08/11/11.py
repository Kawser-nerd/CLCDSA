


f = open(r'C:\goog\A-large.in')

numcases=int(f.readline())
for case in range(numcases):
    line=f.readline().strip()
    n=int(line)
    
    line=f.readline().strip()
    vect1=map(int, line.split(' '))
    
    line=f.readline().strip()
    vect2=map(int, line.split(' '))
    
    if n!= len(vect1) or n!= len(vect2): raise

    vect1.sort()
    vect2.sort()
    
    vect2.reverse()
    
    total=0
    for i in range(n):
        total += vect1[i] * vect2[i]
    

    print "Case #" + str(case+1) + ": " + str(total)
            

        






