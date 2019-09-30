import numpy as np
P=float(input())
x=1.5/np.log(2.000000000)*np.log(P*np.log(2.000000000000)/1.500000000000000)
if(x>0):
	print(x+P*pow(2.0000000000000,-x/1.500000000000000))
else:
	print(P)