X,Y = map(int, input().split('/'))

isImpossible = True

for i in range(2):
    N = int((X/Y*2) // 1+i)
    SigmaN = N*(N+1)//2
 
    if N*X%Y == 0 and N is not 0:
        isImpossible = False
        print(N, end=' ')
        print(SigmaN - (N*X//Y))
    
if isImpossible:
    print("Impossible")