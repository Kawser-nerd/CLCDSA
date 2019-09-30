#!/usr/bin/python3
# -*- coding: utf-8 -*-

ntests = int(input())

for tt in range(1, ntests+1):
	[N, M] = [int(x) for x in input().split()]
	dirs=set()
	for i in range(N):
		p = input()+"/"
		for z in range(len(p)-1):
			if(p[z+1]=='/'):
				dirs.add(p[:(z+1)])
	k=len(dirs)
	for i in range(M):
		p = input()+"/"
		for z in range(len(p)-1):
			if(p[z+1]=='/'):
				dirs.add(p[:(z+1)])
	print("Case #"+str(tt)+": "+str(len(dirs) - k))
