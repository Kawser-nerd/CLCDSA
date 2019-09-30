# -*- coding: utf-8 -*-
import sys
import random

def main():
	Q = int(input())
	maps = []
	r_max = 0
	for _ in range(Q):
		l, r = map(int, input().split(" "))
		maps.append((l, r))
		if r_max < r:
			r_max = r
			
	#marix = getPrimeNumList(r_max)
				
	base = [0] * (r_max+1)
	counts = 0
	for i in range(r_max+1):
		if i == 0 or i == 1:
			continue
		if (i+1) % 2 == 0 and is_prime(i) == True:
			tmp = (i+1) / 2
			if is_prime(tmp) == True:
				counts += 1
		base[i] = counts
			
	
	for i in maps:
		l, r = i
		print(base[r] - base[l-1])
			
		
def getPrimeNumList(n):
	is_prime = [True] * (n + 1)
	is_prime[0] = False
	is_prime[1] = False
	for i in range(2, int(n**0.5) + 1):
		if not is_prime[i]:
			continue
		for j in range(i * 2, n + 1, i):
			is_prime[j] = False
	return [i for i in range(n + 1) if is_prime[i]]
	
def is_prime(n): 
  i = 2
  while i * i <=n:
    if n % i == 0:
      return False
    i += 1
  return True
	
if __name__ == "__main__":
	main()