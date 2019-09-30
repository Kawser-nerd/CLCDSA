# -*- coding: utf-8 -*-

def io_generator():
	return input()

#+++++++++++++++++++

def main(io):
	n =int(io())
	s=io()[:n]
	
	dd={'A':4,'B':3,'C':2,'D':1,'F':0}
	
	aa=[dd[c] for c in s]

	print(sum(aa)/len(aa))
	
#++++++++++++++++++++

if __name__ == "__main__":
	io= lambda : io_generator()
	#print (main(io))
	main(io)