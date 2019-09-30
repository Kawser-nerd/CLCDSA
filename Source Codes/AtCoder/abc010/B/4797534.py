#2,4,6,8,10,12,14
#2,5,8,11,14
#1,3,7,9,13,15
#3n+1 or 3n and %2
#x%3 

from statistics import mean, median,variance,stdev
import sys
import math
import fractions
def j(a):
    if a==1: print("YES")
    else :print("NO")


def ct(x,y):
    if (x>y):print("")
    elif (x<y): print("")
    else: print("")

n = int(input())                              #????1?
#x,y = (int(i) for i in input().split())      #?????2?
#x,y,z = (int(i) for i in input().split())    #?????3?
#a,b,c,k = (int(i) for i in input().split())  #?????4?
a = [int(i) for i in input().split()]        #??????
#x = input()                                  #?????
#a = input().split()                          #??????
s =0
for i in range(n):
	while not((a[i]%3 == 0 or a[i]%3 == 1) and a[i]%2):
		a[i]-=1
		s+=1
print(s)