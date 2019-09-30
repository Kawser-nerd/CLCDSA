
def executer_calcul(entrees):
	B=entrees[0]
	M=entrees[1]
	Case=entrees[2]
	if(M>2**(B-2)): return 'IMPOSSIBLE'+'\n'
	result= 'POSSIBLE'+'\n'
	if(M==2**(B-2)):
		base=''
		for i in range(B-1):
			base=base+'1'
	else: base=base2(M,B-2)+'0'
	print(Case,base)
	for k in range(1,B):
		for i in range(k):
			result=result+'0'
		for i in range(B-k-1):
			result=result+'1'
		result=result+base[B-k-1]+'\n'
	for i in range(B):
		result=result+'0'
	result=result+'\n'
	return result

def base2(M,n):
	result=''
	p=n
	while(p>0):
		if(M%2==0): result='0'+result
		else: result='1'+result
		M=M//2
		p=p-1
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
		B,M=map(int,lines[line].split(' '))
		line=line+1
		entrees=[B,M,Case]
		if (not multiprocessed): output.write('Case #'+str(Case)+': '+executer_calcul(entrees))
		else: calculs.append(entrees)
		Case=Case+1
	if (multiprocessed):
		pool=Pool(3) # Décide du nombre de processus à faire tourner en parallèle
		results=pool.map(executer_calcul,calculs)
		output = open('Output.txt','w')
		for case in range(len(results)):
			output.write('Case #'+str(case+1)+': '+results[case]+'\n')
	output.close()

