# -*- coding: utf-8 -*-

def io_generator():
	return input()

#+++++++++++++++++++

def main(io):
	a=int(io())
	l = list(map(int, io().split()))
	
	l.sort(reverse=True)
	m=sum(l[1:])
	pre=l[0]
	num=1
	for val in l[1:]:
		if pre > m*2:
			break
		else:
			num+=1
			pre=val
			m=m-val
		
	return num

#++++++++++++++++++++

if __name__ == "__main__":
	io= lambda : io_generator()
	print (main(io))