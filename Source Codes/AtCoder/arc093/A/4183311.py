A=int(input())
B=list(map(int,input().split()))
a=0
S=0
for i in range(len(B)):
    S+=abs(B[i]-a)
    a=B[i]
S+=abs(B[-1])
for j in range(len(B)):
    if j==0:
        if 0<=B[0]<=B[1] or 0>=B[0]>=B[1]:
            print(S)
        elif B[0]<=0<=B[1] or B[0]>=0>=B[1]:
            print(S-2*abs(B[0]))
        else:
            print(S-2*abs(B[1]-B[0]))
    elif j==len(B)-1:
        if 0<=B[-1]<=B[-2] or 0>=B[-1]>=B[-2]:
            print(S)
        elif B[-1]<=0<=B[-2] or B[-1]>=0>=B[-2]:
            print(S-2*abs(B[-1]))
        else:
            print(S-2*abs(B[-1]-B[-2]))
    else:
        if B[j-1]<=B[j]<=B[j+1] or B[j-1]>=B[j]>=B[j+1]:
            print(S)
        elif B[j]<=B[j-1]<=B[j+1] or B[j]>=B[j-1]>=B[j+1]:
            print(S-2*abs(B[j-1]-B[j]))
        else:
            print(S-2*abs(B[j+1]-B[j]))