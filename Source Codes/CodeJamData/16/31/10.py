
def executer_calcul(entrees):
	N=entrees[0]
	parties=entrees[1]
	Case=entrees[2]
	result=''
	while (sum(parties)>0):
		evac1=maximum(parties)
		parties[evac1]=parties[evac1]-1
		evac2=maximum(parties)
		if(2*parties[evac2]>sum(parties)):
			parties[evac2]=parties[evac2]-1
			result=result+' '+chr(evac1+65)+chr(evac2+65)
		else:
			result=result+' '+chr(evac1+65)
	return result

def maximum(liste):
	maximum=0
	for i in range(len(liste)):
		if(liste[i]>liste[maximum]): maximum=i
	return maximum

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
		N=int(lines[line])
		line=line+1
		parties=list(map(int,lines[line].split(' ')))
		line=line+1
		entrees=[N,parties,Case]
		if (not multiprocessed): output.write('Case #'+str(Case)+':'+executer_calcul(entrees)+'\n')
		else: calculs.append(entrees)
		Case=Case+1
	if (multiprocessed):
		pool=Pool(3) # Décide du nombre de processus à faire tourner en parallèle
		results=pool.map(executer_calcul,calculs)
		output = open('Output.txt','w')
		for case in range(len(results)):
			output.write('Case #'+str(case+1)+': '+results[case]+'\n')
	output.close()

