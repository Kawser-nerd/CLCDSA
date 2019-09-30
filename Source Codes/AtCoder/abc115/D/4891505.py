# -*- coding: utf-8 -*-

def io_generator():
	return input()

#+++++++++++++++++++

def n_pat(a_n):
	return 2**a_n - 1
	
def n_size(a_n):
	return 4 * (2** (a_n -1))- 3
	
def get_size(n,x):
	if x == 0:
		return 0
	elif x==1:
		return 0
	elif x < 1 + n_size(n):
		return get_size(n-1, x -1)
	elif x == 1 + n_size(n):
		return n_pat(n)
	elif x == 1 + n_size(n) + 1:
		return n_pat(n) + 1
	elif x < 1 + n_size(n) +1 + n_size(n):
		offset=2 + n_size(n)
		return n_pat(n)+1+get_size(n-1, x - offset)
	else:#if x == 1+n_size(n)+1+n_size(n):
		return n_pat(n)+1+n_pat(n)

def main(io):
	n,x= map(int, io().split())
	return get_size(n,x)
	#for i in range(1,51):
	#	print(n_pat(i),n_size(i))
	#return str(a+b+c) + " " + s

#++++++++++++++++++++

if __name__ == "__main__":
	io= lambda : io_generator()
	print (main(io))