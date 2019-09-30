from random import randint

T = int(input())

def try_random(B,X):
    x = randint(1,max(X))    
    treba = 0
    pocet = 0
    for y in X:
        if y <= x:
            treba += x-y
            pocet += 1
    if treba > B: return (x,0)
    if pocet==0: return (x,0)
    pp = 1. / pocet
    return (x, 36. * pp * treba - treba)

for t in range(1,T+1):
    B, N = [ int(x) for x in input().split() ]
    X = [ int(x) for x in input().split() ]
    X += [ 0 ] * (37-N)
    X.sort()
    best_profit = 0.

    # skusime robit len moje kopky
    for najmensich in range(1,37):
        if X[-1] == X[najmensich-1]: continue

        mintreba = 0
        for i in range(najmensich):
            mintreba += X[najmensich-1] - X[i]
        for i in range(najmensich,37):
            if X[i] == X[najmensich-1]: mintreba += 1

        if mintreba > B: continue
        minvyska = X[najmensich-1]

        if True:
            vyska = minvyska

            treba = 0
            vyhra = 0
            for i in range(najmensich):
                treba += vyska - X[i]
                vyhra += vyska - X[i]
            for i in range(najmensich,37):
                if X[i] <= vyska:
                    treba += vyska+1-X[i]

            pp = 1. / najmensich
            best_profit = max( best_profit, 36.*pp*vyhra - treba )

        maxvyska = X[-1] # uz je zla

        while maxvyska - minvyska > 1:
            vyska = (maxvyska + minvyska)//2

            treba = 0
            vyhra = 0
            for i in range(najmensich):
                treba += vyska - X[i]
                vyhra += vyska - X[i]
            for i in range(najmensich,37):
                if X[i] <= vyska:
                    treba += vyska+1-X[i]
            
            if treba <= B:
                pp = 1. / najmensich
                best_profit = max( best_profit, 36.*pp*vyhra - treba )
                minvyska = vyska
            else:
                maxvyska = vyska

    # a este skusime dorovnat vsetko na vysku najvacsej kopky a mozno navysit niekolko najvacsich
    treba = 0
    vyhra = 0
    vyska = X[-1]
    for i in range(37):
        treba += vyska - X[i]
        vyhra += vyska - X[i]
    pp = 1. / 37
    if treba <= B:
        best_profit = max( best_profit, 36.*pp*vyhra - treba )

        najvacsich = 0
        for i in range(37):
            if X[i]==X[-1]: najvacsich += 1
        for i in range(1,najvacsich):
            if treba+i > B: break
            pp = 1. / (37-i)
            best_profit = max( best_profit, 36.*pp*vyhra - treba - i )

    print('Case #{}: {:.20f}'.format(t,best_profit))

