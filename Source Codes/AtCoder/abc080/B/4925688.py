N=int(input())
S=sum(map(int,list(str(N))))
if N%S==0:
    print("Yes")
else:
    print("No")