e=[int(i) for i in input().split()]
b=int(input())
l=[int(i) for i in input().split()]

same=set(e) & set(l)
notin,same=set(l)-same,list(same)
if len(same)==6:
	print(1)
elif len(same)>=5:
	if notin=={b}:
		print(2)
	else:
		print(3)	
elif len(same)>=4:
	print(4)
elif len(same)>=3:
	print(5)
else:
	print(0)