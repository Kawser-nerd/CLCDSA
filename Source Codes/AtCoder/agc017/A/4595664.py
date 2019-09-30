N,P=map(int,input().split())
a=list(map(int,input().split()))
a=list(map(lambda x:x%2,a))
if 1 in a:
    print(2**(N-1))
else:
    if P%2==0:
        print(2**N)
    else:
        print(0)