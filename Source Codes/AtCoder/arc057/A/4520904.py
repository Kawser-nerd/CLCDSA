A,K=input().split()
A=int(A)
K=int(K)
if K==0:
    print(2*10**12-A)
else:
    day=0
    while True:
        A+=1+K*A
        day=day+1
        if A>=2*10**12:
            break
    print(day)