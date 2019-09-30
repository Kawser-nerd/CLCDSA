Q,H,S,D = map(int,input().split())
N = int(input())  

C = min(4*Q,2*H,S)
if 2*C<=D:
    print(N*C)
elif N%2==0:
    print(N*D//2)  
else:
    print((N//2)*D+C)