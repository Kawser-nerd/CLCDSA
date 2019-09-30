N=int(input())

A1=0
A2=0
A3=0
A4=0
A5=0
A6=0

for i in range(N):
    M,m=map(float,input().split())
    if M>=35:
        A1+=1
    elif M>=30:
        A2+=1
    elif M>=25:
        A3+=1
    if m>=25:
        A4+=1
    if M>=0 and 0>m:
        A5+=1
    if 0>M:
        A6+=1
        
print(A1,A2,A3,A4,A5,A6)