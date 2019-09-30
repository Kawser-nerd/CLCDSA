N,M = map(int,input().split())
 
if N == 2 or M == 2:
    print(0)
    exit()

if N == 1:
    if M == 1:
        print(1)
    else:
        print(M-2)
    exit()

if M == 1:
    print(N-2)
    exit()

print((N-2)*(M-2))