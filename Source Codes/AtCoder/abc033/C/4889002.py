s=input()
A=[]
X=[]
for i in range(1,len(s),2):
    X.append(s[i-1])
    if s[i]=='+':
        A.append(X)
        X=[]
    if i==len(s)-2:
        X.append(s[len(s)-1])
        A.append(X)

cnt=0
for x in A:
    if '0' not in x:
        cnt+=1
if len(s)==1 and s!='0':
    cnt=1
    
print(cnt)