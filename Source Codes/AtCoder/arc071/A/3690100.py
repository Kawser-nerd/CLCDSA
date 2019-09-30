n=int(input())
S=[]
T=[]
U=""
for i in range(1,n+1):
    S.append(input())
for i in range(97,123):
    T.append(min(S[j].count(chr(i)) for j in range(len(S))))
for k in range(len(T)):
    U+=chr(k+97)*T[k]
print(U)