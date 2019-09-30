N=int(input())
C=input()
BUT=["A","B","X","Y"]

SHORT=[]
for i in range(4):
    for j in range(4):
        SHORT.append(BUT[i]+BUT[j])

#print(SHORT)
ans=0
for i in range(len(SHORT)):
    for j in range(len(SHORT)):
        S=C.replace(SHORT[i],"L")
        S=S.replace(SHORT[j],"L")
        if ans<S.count("L"):
            ans=S.count("L")
print(N-ans)