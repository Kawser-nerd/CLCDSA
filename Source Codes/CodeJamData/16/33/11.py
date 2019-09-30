
def executer_calcul(entrees):
	J=entrees[0]
	P=entrees[1]
	S=entrees[2]
	K=entrees[3]
	Case=entrees[4]
	if(K>S): K=S
	if(P>=K): S=P
	result=str(J*P*K)
	for j in range(J):
		for p in range(P):
			for k in range(K):
				result=result+'\n'+str(j+1)+' '+str(p+1)+' '+str((p+j+k)%S+1)
	return result


# Main
multiprocessed=False # Décide si l'on parallélise les calculs pour gagner du temps
if (multiprocessed): from multiprocessing import Pool
else: output = open('Output.txt','w')
if ((not multiprocessed) or __name__ == '__main__'):
	with open("Input.txt", "r") as input:
		lines=input.readlines()
	T=int(lines[0])
	line=1
	Case=1
	calculs=[]
	while(line<len(lines)):
		J,P,S,K=map(int,lines[line].split(' '))
		line=line+1
		entrees=[J,P,S,K,Case]
		if (not multiprocessed): output.write('Case #'+str(Case)+': '+executer_calcul(entrees)+'\n')
		else: calculs.append(entrees)
		Case=Case+1
	if (multiprocessed):
		pool=Pool(3) # Décide du nombre de processus à faire tourner en parallèle
		results=pool.map(executer_calcul,calculs)
		output = open('Output.txt','w')
		for case in range(len(results)):
			output.write('Case #'+str(case+1)+': '+results[case]+'\n')
	output.close()

