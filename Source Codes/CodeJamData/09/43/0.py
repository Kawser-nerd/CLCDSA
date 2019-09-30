#!/usr/bin/env python2.6
import os, sys, re, math
stdin = sys.stdin

def maxmatching(G):
	N = len(G)
	ymatch = [-1] * N
	seen = []
	
	def dfs(i):
		if seen[i]:
			return 0
		
		seen[i] = 1
		for j in range(N):
			if G[i][j] and ((ymatch[j] == -1) or dfs(ymatch[j])):
				ymatch[j] = i
				return 1
		return 0	

	res = 0
	for i in range(N):
		seen = [0] * N
		res += dfs(i)
	return res

def Less(a, b):
	assert len(a) == len(b)
	return all(a[i] < b[i] for i in range(len(a)))


def main():
	T = int(stdin.readline())
	for cs in range(1, T+1):
		N, K = map(int, stdin.readline().split())
		
		stocks = []
		for each in range(N):
			stocks.append(map(int, stdin.readline().split()))
			
		G = [[0] * N for each in range(N)]
		for i in range(N):
			for j in range(N):
				if Less(stocks[i], stocks[j]):
					G[i][j] = 1

		print 'Case #%d: %s' % (cs, N - maxmatching(G))

main()
