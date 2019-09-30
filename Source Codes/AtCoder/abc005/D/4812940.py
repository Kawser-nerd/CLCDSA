# -*- coding: utf-8 -*-
import sys

def main():
	N = int(input())
	D = []
	for _ in range(N):
		tmp = input().split(" ")
		tmp = [int(s) for s in tmp]
		D.append(tmp)
	Q = int(input())
	P = []
	for _ in range(Q):
		tmp = int(input())
		P.append(tmp)
	
	maps = [[-1 for _ in range(N)] for _ in range(N)]
	maps[0][0] = D[0][0]
	for i in range(N):
		for j in range(N):
			if i == 0 and j == 0: continue
			if i == 0:
				maps[j][i] = maps[j-1][i] + D[j][i]
				continue
			if j == 0:
				maps[j][i] = maps[j][i-1] + D[j][i]
				continue
			maps[j][i] = maps[j][i-1] + maps[j-1][i] - maps[j-1][i-1] + D[j][i]
	
	ans_list = [-1 for _ in range(N*N+1)]
	for i_s in range(N):
		for i_e in range(i_s, N):
			for j_s in range(N):
				for j_e in range(j_s, N):
					
					tmp = (i_e - i_s + 1) * (j_e - j_s + 1)
					tmp_hpp = 0
					if i_s == 0 and j_s == 0:
						tmp_hpp = maps[j_e][i_e]
					elif i_s == 0:
						tmp_hpp = maps[j_e][i_e] - maps[j_s-1][i_e]
					elif j_s == 0:
						tmp_hpp = maps[j_e][i_e] - maps[j_e][i_s-1]
						#print("{} {}".format(maps[j_e][i_e] , maps[j_e][i_e-1]))
						#print("{} {} {} {} - {}".format(i_s, i_e, j_s, j_e, tmp_hpp))
					else:
						tmp_hpp = maps[j_e][i_e] - maps[j_s-1][i_e] - maps[j_e][i_s-1] + maps[j_s-1][i_s-1]
					
					#if tmp == 3:
						#print("{} {} {} {} - {}".format(i_s, i_e, j_s, j_e, tmp_hpp))
					if ans_list[tmp] < tmp_hpp:
						ans_list[tmp] = tmp_hpp
	
	max = 0
	#print(maps)
	for i in range(len(ans_list)):
		if max < ans_list[i]:
			max = ans_list[i]
		else:
			ans_list[i] = max
	
	for i, val in enumerate(P):
		print(ans_list[val])
		
	
	
if __name__ == "__main__":
	main()