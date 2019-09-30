import math
import copy
temp=input().split()
H=int(temp[0])
W=int(temp[1])
K=int(temp[2])
A=[[i for i in input()] for j in range(H)]
place=[[K+2 for j in range(W)] for i in range(H)]
ans=0

si=0
sj=0
for i in range(H):
	for j in range(W):
		if A[i][j]=="S":
			si=i
			sj=j
			A[i][j]="."
			break
	else:
		continue
	break

now=[[si,sj]]
place[si][sj]=0
next=[]
for i in range(K):
	for room in now:
		if A[room[0]-1][room[1]]=="." and place[room[0]-1][room[1]]==K+2:
			place[room[0]-1][room[1]]=i
			next.append([room[0]-1,room[1]])
			if room[0]-1==0:
				ans=-1
		if A[room[0]+1][room[1]]=="." and place[room[0]+1][room[1]]==K+2:
			place[room[0]+1][room[1]]=i
			next.append([room[0]+1,room[1]])
			if room[0]+1==H-1:
				ans=-1
		if A[room[0]][room[1]-1]=="." and place[room[0]][room[1]-1]==K+2:
			place[room[0]][room[1]-1]=i
			next.append([room[0],room[1]-1])
			if room[1]-1==0:
				ans=-1
		if A[room[0]][room[1]+1]=="." and place[room[0]][room[1]+1]==K+2:
			place[room[0]][room[1]+1]=i
			next.append([room[0],room[1]+1])
			if room[1]+1==W-1:
				ans=-1
	if ans==-1:
		break
	now=copy.deepcopy(next)
	next=[]
		
little=H+W
goodi=-1
goodj=-1
for i in range(H):
	for j in range(W):
		if place[i][j]!=K+2:
			little=min(little,i,j,H-1-i,W-1-j)
			goodi=i
			goodj=j
print(math.ceil(little/K)+1)