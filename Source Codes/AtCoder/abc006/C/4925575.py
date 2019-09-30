N, M = map(int,input().split())
if M/N >4 or M/N<2:
    print("-1 -1 -1")
else:
    a = M-N*3
    if(a<0):
        print(-a,a+N,0)
    else:
        print(0,N-a,a)