S = input()+'!'
for i in range(len(S)):
	if S[i] == 'I' or S[i] == 'i':
		for j in range(i+1,len(S)):
			if S[j] == 'C' or S[j] == 'c':
				for k in range(j+1,len(S)):
					if S[k] == 'T' or S[k] == 't':
						print("YES")
						exit()
print("NO")