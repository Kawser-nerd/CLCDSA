S=list(input())
T=int(input())

dic={'U':0,'D':0,'R':0,'L':0}

ct=0
for s in S:
	if s!='?':
	    dic[s]=dic.get(s,0)+1
	else:
		ct+=1

A=abs(dic['U']-dic['D'])+abs(dic['L']-dic['R'])
print(A+ct if T==1 else max(len(S)%2, A-ct))