#100
D,N= map(int,input().split())
ans =(100**D)*N
if N==100:
    print((100**D)*101)
else:
    print(ans)