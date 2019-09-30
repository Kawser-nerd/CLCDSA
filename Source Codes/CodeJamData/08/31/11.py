def keys(num_per_key,num_keys,num_letters,frequencies):
    frequencies.sort()
    iterations = 0
    answer = 0
    while len(frequencies) > 0 and iterations < num_per_key:
        iterations += 1
        for i in range(0,min(len(frequencies),num_keys)):
            answer += frequencies.pop() * iterations
    if len(frequencies) > 0:
        return -1
    else:
        return answer
            
            
        
    
    



N = int(raw_input())
for i in range(1,N+1):
    per,key,let = raw_input().split(' ')
    freq = raw_input().split(' ')
    freq = map(int,freq)
    print "Case #%d: %d" % (i,keys(int(per),int(key),int(let),freq))
