i = input()
x = [s.strip() for s in i.split('/')]
if int(x[0])<2019:
	print('Heisei')
elif int(x[0])==2019:
	if int(x[1])<5:
		print('Heisei')
	else:
		print('TBD')
else:
	print('TBD')