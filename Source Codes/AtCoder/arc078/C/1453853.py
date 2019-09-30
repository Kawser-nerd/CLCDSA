for k in range(1,10):
    print('?',10**k,flush=True)
    if input()=='N':
        i=10**(k-1)+1
        j=10**k-1
        while i<j:
            m=(i+j)//2
            print('?',m*10,flush=True)
            if input()=='Y':
                j=m
            else:
                i=m+1
        print('!',i,flush=True)
        break
else:
    for k in range(10):
        print('?',10**(k+1)-1,flush=True)
        if input()=='Y':
            print('!',10**k,flush=True)
            break