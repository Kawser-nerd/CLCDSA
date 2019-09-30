S=list(input())
N=len(S)

if N==1:
    print(0)

elif N%2==1:
    same=0
    for i in range(N):
        if S[i]==S[N-1-i]:
            same+=1
    same-=1
    same=(same//2)
    
    if same==(N//2):
        print(25*(N//2)*2)
    elif same==(N//2)-1:
        print(25*(N//2-1)*2+24*2+25)
    else:
        print(25*N)
else:
    same=0
    for i in range(N):
        if S[i]==S[N-1-i]:
            same+=1
    same=(same//2)
    
    if same==(N//2):
        print(25*N)
    elif same==(N//2)-1:
        print(25*(N//2-1)*2+24*2)
    else:
        print(25*N)