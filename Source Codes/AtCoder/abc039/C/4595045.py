#ABC039C
S=input()
A=['Do','Re','Mi','Fa','So','La','Si']
k='WBWBWWBWBWBW'*4
K=[]
for i in range(12):
    if k[i]=='W':
        K.append(k[i:i+20])
for i in range(7):
    if S==K[i]:
        print(A[i])
        break