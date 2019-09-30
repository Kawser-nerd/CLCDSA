import  collections
dic=collections.Counter(list(input()))
if max((dic.values()))==1:
	print('yes')
else:print('no')