n=int(input().strip())
slis={'a':0,'b':0,'c':0,'d':0,'e':0,'f':0,'g':0,'h':0,'i':0,'j':0,'k':0,'l':0,'m':0,'n':0,'o':0,'p':0,'q':0,'r':0,'s':0,'t':0,'u':0,'v':0,'w':0,'x':0,'y':0,'z':0}
tlis={'a':0,'b':0,'c':0,'d':0,'e':0,'f':0,'g':0,'h':0,'i':0,'j':0,'k':0,'l':0,'m':0,'n':0,'o':0,'p':0,'q':0,'r':0,'s':0,'t':0,'u':0,'v':0,'w':0,'x':0,'y':0,'z':0}
st=''
S=input().strip()
for j in range(len(S)):
        slis[S[j]]+=1
for i in range(n-1):
    S=input().strip()
    for j in range(len(S)):
        tlis[S[j]]+=1
    for j in tlis:
        slis[j]=min(tlis[j],slis[j])
    for j in tlis:
        tlis[j]=0
stup=[]
for i in slis:
    stup.append((i,slis[i]))
stup.sort()

for i in range(26):
    st=st+stup[i][0]*stup[i][1]
    
print(st)