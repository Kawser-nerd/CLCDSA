#!/usr/bin/python



    
def doit():
    (N,M,K) = raw_input().split()
    N = int(N)
    M = int(M)
    K = int(K)
    
    if (N<3) or (M<3):
        return K
        
    if N > M:
        (N,M) = (M,N)
        
    if N == 3:
        if K<=4:
            return K
        
        maxsave = M-2
        save = (K-2)/3
        if save > maxsave:
            save=maxsave
        return K-save
    
    if N == 4:
        maxsave = (M-2)*(N-2)
        if K<5:
            save = 0
        elif K < 8:
            save = 1
        elif K < 10:
            save = 2
        elif K < 12:
            save = 3
        elif K < 14:
            save = 4
        elif K < 16:
            save = 5
        else:
            save = 6
        if save > maxsave:
            save=maxsave
        return K-save
            
    else:
        
        if K<5:
            save = 0
        elif K < 8:
            save = 1
        elif K < 10:
            save = 2
        elif K < 12:
            save = 3
        elif K < 13:
            save = 4
        elif K < 15:
            save = 5
        elif K < 17:
            save = 6
        elif K < 19:
            save = 7
        elif K < 21:
            save = 8
        else:
            save = 9
        
        return K-save


cases = input()
for case in range(1, cases+1):
    
    print ("Case #" + str(case) + ":"),
    print doit()
