N=int(input())
LIST=[0,0]

for i in range(2,N+1):
    print("?",1,i,flush=True)
    LIST.append(int(input()))

x=LIST.index(max(LIST))

ANS=[]
for i in range(1,N+1):
    if i==x:
        continue
    else:
        print("?",x,i)
        ANS.append(int(input()))

print("!",max(ANS))