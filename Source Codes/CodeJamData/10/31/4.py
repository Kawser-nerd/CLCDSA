T=int(input())

for testCase in range(0,T):
    N=int(input())
    A=[]
    for n in range(0, N):
        line = input().split()
        A.append((int(line[0]),int(line[1])))
    A.sort()
    s=0
    for a0, b0 in A:
        i=0
        while A[i][0] < a0:
            if A[i][1] > b0:
                s+=1
            i+=1
    print('Case #{0}: {1}'.format(testCase+1, s))
