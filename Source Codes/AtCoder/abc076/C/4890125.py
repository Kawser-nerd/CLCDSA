S=input()
T=input()
flag=False
for i in range(len(S)-len(T)+1):
    dif=0
    same=0
    s=S[i:i+len(T)]#len(T)
    for j in range(len(T)):
        if s[j]!='?':#s?????
            if s[j]!=T[j]:
                #print("st",s[i],T[i])
                dif+=1
            else:
                same+=1
#                flag=True

        #else:#????
    if dif==0:
        #dst=S.replace(s,T)
        flag=True
        memo=i#??replace??
    



if flag==False:
    print("UNRESTORABLE")
else:
    S=list(S)
    for i in range(len(T)):
        S[i+memo]=T[i]
    
    S=''.join(S)    
    S=S.replace('?','a')
    print(S)