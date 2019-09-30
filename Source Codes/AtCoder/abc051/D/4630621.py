# -*- coding: utf-8 -*-
import sys
import copy

def main():
	N, M = map(int, input().split(" "))
	
	graph = []
	maps = [[9999999 for _ in range(N)] for _ in range(N)]
	for i in range(N):
		maps[i][i] = 0
	
	for _ in range(M):
		a, b, c = map(int, input().split(" "))
		a, b = a-1, b-1
		maps[a][b] = c
		maps[b][a] = c
	
	ans = 0
	org = copy.deepcopy(maps)
	for k in range(N):
		for i in range(N):
			for j in range(N):
				#if maps[i][j] == 9999999:
					#continue
				if i <= j:
					continue
				maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j])
				maps[j][i] = min(maps[i][j], maps[i][k] + maps[k][j])
			
	for i in range(N):
		for j in range(N):
			if i <= j:
				continue
			if org[i][j] == 9999999:
				continue
			if org[i][j] != maps[i][j]:
				ans += 1
		
	print(ans)
	
if __name__ == "__main__":
	main()