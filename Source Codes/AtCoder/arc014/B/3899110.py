N=int(input())
W1=input()
A=[]
A.append(W1)

for i in range(N-1):
    w=input()
    
    if w[0]==A[len(A)-1][-1]:
        if w not in A:
            A.append(w)
        else:
            if i%2==0:
                print("WIN")
                exit()
            else:
                print("LOSE")
                exit()
    else:
        if i%2==0:
            print("WIN")
            exit()
        else:
            print("LOSE")
            exit()

print("DRAW")