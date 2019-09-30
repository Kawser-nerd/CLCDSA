import numpy as np
import math

inname = "input.txt"
outname = "output.txt"


with open(inname, 'r') as f:
	cases = int(f.readline())
	for tc in range(1,cases+1):
		line = f.readline().strip().split(' ')
		N = int(line[0])
		C = int(line[1])
		M = int(line[2])
		Cnum = [0]*C
		Nnum = [0]*N
		for i in range(M):
			line = f.readline().strip().split(' ')
			p = int(line[0])
			b = int(line[1])
			Nnum[p-1] += 1
			Cnum[b-1] += 1
			
		Nsum = [0]*(N+1)
		for i in range(N):
			Nsum[i+1] = Nsum[i]+Nnum[i]
		y = 0
		for i in range(C):
			if Cnum[i] > y:
				y = Cnum[i]
		for i in range(N):
			a = math.ceil(Nsum[i+1]/(i+1))
			if a > y:
				y = a
		z = 0
		for i in range(N):
			if Nnum[i] > y:
				z += Nnum[i]-y

		print("Case #%d: %d %d" % (tc, y, z))
