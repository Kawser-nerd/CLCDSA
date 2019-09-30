N = bin(int(input()))[2:]
ret = ['Aoki','Takahashi']
point = 0
for i in range(1,len(N)):
	if N[i] == '0':
		if i % 2 != (len(N)-1) % 2:
			print(ret[i%2])
			break
	if N[i] == '1':
		if i % 2 == (len(N)-1) % 2:
			print(ret[i%2])
			break
else:
	print(ret[(len(N)-1) % 2])