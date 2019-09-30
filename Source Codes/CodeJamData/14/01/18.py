f = open('testin.in', 'r')
data = f.read().split('\n')

#print data
cases = int(data[0])
#print "cases:" + str(cases)
for case in xrange(cases):
    ans1 = int( data[1 + case*10])
    grid1 = data[2 + case*10: 1+ case*10 + 5]
    grade1 = [map(int, line.split(' ')) for line in grid1]
    set1 = set(grade1[ans1-1])

    #print ans1, grade1,set1

    ans2 = int( data[1+ case* 10 + 5])
    grid2 = data[7 + case*10: 11 + case*10]
    grade2 = [map(int, line.split(' ')) for line in grid2]
    set2 = set(grade2[ans2-1])

    #print ans2, grade2, set2

    ans = set1.intersection(set2)
    
    if len(ans) ==1:
        show = str(ans.pop())
    elif        len(ans) ==0:
        show = "Volunteer cheated!"
    else:
        show = "Bad magician!"

    print "Case #%d: %s" % (case+1, show)

