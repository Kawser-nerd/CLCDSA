#!/usr/bin/env python

inf=file('B-large.in','r')
outf=file('B-large.out','w')
casenum=int(inf.readline())
for i in range(0,casenum):
	T=int(inf.readline())
	tmp=inf.readline()
	NA=int(tmp.split(' ')[0])
	NB=int(tmp.split(' ')[1])
	DA=[]
	AA=[]
	DB=[]
	AB=[]
	a=0
	b=0
	for j in range(0,NA):
		tmp=inf.readline()
		DA.append(int(tmp.split(' ')[0].split(':')[0])*60+int(tmp.split(' ')[0].split(':')[1]))
		AA.append(int(tmp.split(' ')[1].split(':')[0])*60+int(tmp.split(' ')[1].split(':')[1]))
	for j in range(0,NB):
		tmp=inf.readline()
		DB.append(int(tmp.split(' ')[0].split(':')[0])*60+int(tmp.split(' ')[0].split(':')[1]))
		AB.append(int(tmp.split(' ')[1].split(':')[0])*60+int(tmp.split(' ')[1].split(':')[1]))
	DA.sort()
	AA.sort()
	DB.sort()
	AB.sort()
	for j in DA:
		if AB!=[]:
			if j < AB[0]+T:
				a+=1
			else:
				del(AB[0])
		else:
			a+=1
	for j in DB:
		if AA!=[]:
			if j < AA[0]+T:
				b+=1
			else:
				del(AA[0])
		else:
			b+=1
	outf.write('Case #%d: %d %d\n'%(i+1,a,b))

inf.close()
outf.close()
