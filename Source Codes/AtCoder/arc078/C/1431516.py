# E

# keta
query = 10**9

print('? '+str(query))
res = input()
# res = sunuke(query)

if res == 'Y':
    # N = 10**p
    query *= 2
    # str(query) > str(N)
    for i in range(10):
        query = query // 10
        if query == 0:
            break
        print('? '+str(query))
        res = input()
        # res = sunuke(query)
        
        if res == 'N':
            break
    if query > 0:
        print('! '+str(query*5))
    else:
        print('! 1')
            
else:
    for i in range(9):
        query = query // 10
        
        print('? '+str(query))
        res = input()
        # res = sunuke(query)
        
        if res == 'Y':
            break
    # binary search
    # always query > N
    # query < N < query*10
    # binary search
    # 'N' means query < N
    min_N = query
    max_N = query*10 - 1
    cnt = 0
    
    while cnt < 100:
        query = (min_N + max_N) // 2
        if min_N + 1 >= max_N:
            print("! "+str(max_N))
            break
        
        print('? '+str(query*10))
        res = input()
        # res = sunuke(query)
        cnt += 1
        if res == 'N':
            min_N = query
        else:
            max_N = query