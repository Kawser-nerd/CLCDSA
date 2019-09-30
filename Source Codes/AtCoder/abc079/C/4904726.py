s = input()

a = int(s[0])
b = int(s[1])
c = int(s[2])
d = int(s[3])

one = -1
flg = False

for i in range(2):
	for j in range(2):
		for k in range(2):
			if a + b*one**i + c*one**j + d*one**k == 7:
				flg = True
				break
		if flg:
			break
	if flg:
		break
                
if i == 0 :
	i_flg = "+"
else:
	i_flg = "-"

if j == 0 :
	j_flg = "+"
else:
	j_flg = "-"

if k == 0 :
	k_flg = "+"
else:
	k_flg = "-"

print(a,i_flg,b,j_flg,c,k_flg,d,"=7",sep='')