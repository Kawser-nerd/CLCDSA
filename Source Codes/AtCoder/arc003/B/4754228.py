# -*- coding: utf-8 -*-

def io_generator():
	return input()

#+++++++++++++++++++

def main(io):
	n =int(io())
	ll=[]
	for i in range(n):
		ll.append(io())
	
	ll2=[l[::-1] for l in ll]
	ll2.sort()
	
	for l in ll2:
		print(l[::-1])
	
#++++++++++++++++++++

if __name__ == "__main__":
	io= lambda : io_generator()
	#print (main(io))
	main(io)