# -*- coding: utf-8 -*-

def io_generator():
	return input()

#+++++++++++++++++++

def main(io):
	ret_ng='NO'
	ret_ok='YES'
	
	n=int(io())
	l= list(map(int, io().split()))
	
	v_one_act =n*(n+1)/2
	
	if sum(l)%v_one_act != 0:
		return ret_ng
		
	act_num=sum(l)//v_one_act	
	st_num=0
	
	for a,b in zip(l, l[1:]+l):
		diff = b - a
		if (act_num-diff)%(n)!=0:
			return ret_ng
		if (act_num-diff)<0:
			return ret_ng
		st= (act_num-diff)//(n)
		st_num+=st
	
	if act_num!=st_num:
		return ret_ng
		
	
		
	return ret_ok

#++++++++++++++++++++

if __name__ == "__main__":
	io= lambda : io_generator()
	print (main(io))