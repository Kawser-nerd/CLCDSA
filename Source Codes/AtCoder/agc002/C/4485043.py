n,l=map(int,input().split())
A=list(map(int,input().split()))
for i in range(n-1):
    if A[i]+A[i+1]>=l:
        print('Possible')
        t=i+1
        break
else:
    print('Impossible')
    exit()
for i in range(1,t):
    print(i)
for i in range(n-1,t,-1):
    print(i)
print(t)