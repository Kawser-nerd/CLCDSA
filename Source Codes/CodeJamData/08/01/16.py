filename = raw_input("Enter input file name: ")
input = file(filename,'r')

filename = raw_input("Enter output file name: ")
output = file(filename,'w')


numCases = eval(input.readline())

#print 'number of cases: ', numCases

for case in range(numCases):

    engines = []
    
    numEngines = eval(input.readline())
#    print 'number of engines: ', numEngines
    for e in range(numEngines):
        engName = input.readline()
        engines.append(engName.strip())

#    print 'case, engines: ',case+1,engines

    numQueries = eval(input.readline())
#    print 'number of queries: ', numQueries
    
    queries = []
    for q in range(numQueries):
        qString = input.readline()
        queries.append(qString.strip())

#    print queries
    
    switches = 0
    done = False

    while queries:
        dist = [0]*numEngines
        for (count,eng) in enumerate(engines):
            try:
                dist[count] = queries.index(eng)
            except ValueError:
                done = True
                break  # we're done!
#            print eng, dist

        if done: break
        switches = switches + 1
        maxDist = max(dist)
        queries = queries[maxDist:]

#        print queries

    print 'Case #%s: %s' % (case+1,switches)
    output.write('Case #%s: %s\n' % (case+1,switches))
