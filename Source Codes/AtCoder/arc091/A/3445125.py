N,M=map(int,input().split())
if N==1 and M==1:
    print(1)
elif N==1 or M==1:
    print(N*M-2)
else:
    print(N*M-N*2-M*2+4)