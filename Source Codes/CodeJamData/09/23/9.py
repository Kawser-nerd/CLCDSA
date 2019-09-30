#! /usr/bin/python

import sys
import heapq


class Squ(object):
        def __init__(self, grid):
                self.w = len(grid)
                self.grid = grid
        def at(self, (i,j)):
                return self.grid[i][j]
        def neighbours(self, (i,j)):
                return [(ii,jj) for ii,jj in [(i+1,j-1), (i,j-1), (i-1,j-1), (i+1,j), (i-1,j), (i+1,j+1), (i,j+1), (i-1,j+1)] if ii >= 0 and jj>=0 and ii<self.w and jj<self.w]
        def lex_neighbours(self, (i,j)):
		ns = self.neighbours((i,j))
		ns.sort(key=lambda ij:ord(self.at(ij)))
		return ns
	def ev(self, cs):
		cs = '0+'+cs
		if cs[-1] in "-+": cs = cs[:-1]
		return eval(cs)
	def starts(self,goal):
		out = []
		for i in xrange(self.w):
			for j in xrange(self.w):
				c = self.at((i,j))
				if c.isdigit(): 
					cost = 1
					out.append((cost,c,(i,j),int(c)))
		return out
	def valid_next(self,cs,ns):
		if cs == '' or cs[-1] == '-' or cs[-1] == '+':
			return [n for n in ns if self.at(n) not in '+-']
		else:
			return [n for n in ns if self.at(n) in '+-']
	def tailstrip(self,ccs):
		if ccs[-1:] in ['-','+']: return ccs[:-1]
		return ccs
	def find(self,goal):
		cands = self.starts(goal)
		heapq.heapify(cands)
		occurs = set()
		
		while True:
			cand = heapq.heappop(cands)
			cost,cs,pos,v = cand
			if v == goal: return self.tailstrip(cs)
			if (v,pos) in occurs: continue
			occurs.add((v,pos))
        		ns = self.lex_neighbours(pos)
			ns = self.valid_next(cs,ns)
			for nn in ns:
				ccs = cs+self.at(nn)
				v = self.ev(ccs)
				if v == goal: return self.tailstrip(ccs)
				cost = len(ccs)
				heapq.heappush(cands, (cost,ccs,nn,v) )

if __name__ == '__main__':

	tests = int(sys.stdin.readline().strip())
	
	for testcase in xrange(1,tests+1):
		width,nqueries = map(int,sys.stdin.readline().strip().split())
		grid = [sys.stdin.readline().strip() for i in xrange(width)]
		queries = map(int,sys.stdin.readline().strip().split())
		assert len(queries) == nqueries
		
		print "Case #%d:" % (testcase,)
		s = Squ(grid)
		for q in queries:
			print s.find(q)
