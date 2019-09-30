A,K=list(map(int,input().split()))
day=0
if K!=0:
    while A<2*(10**12):
        A=1+(K+1)*A
        day+=1
    print(day)
else:
    print(int(2*(10**12)-A))