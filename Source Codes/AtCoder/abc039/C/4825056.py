s=input()
X=[]
A=['Do','Re','Mi','Fa','So','La','Si']
for i in range(19):
    if s[i]=='W' and s[i+1]=='W':
        X.append(i)
        
if X[1]-X[0]==7:
    if X[0]==0:
        print(A[2])
    elif X[0]<3:
        print(A[1])
    else:
        print(A[0])
else:
    if X[0]==0:
        print(A[6])
    elif X[0]<3:
        print(A[5])
    elif X[0]<5:
        print(A[4])
    else:
        print(A[3])