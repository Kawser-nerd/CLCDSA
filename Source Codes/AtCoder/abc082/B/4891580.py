# -*- coding: utf-8 -*-

def io_generator():
	return input()

#+++++++++++++++++++

def main(io):
	s=list(io())
	s.sort()
	t=list(io())
	t.sort(reverse = True)
	return 'Yes' if s < t else 'No'

#++++++++++++++++++++

if __name__ == "__main__":
	io= lambda : io_generator()
	print (main(io))