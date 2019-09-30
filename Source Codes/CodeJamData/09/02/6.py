#!/usr/bin/env python

def next_cell(m, x, y):
	"Given a 2d elevation array in m, find the cell that x, y flows to, or None if it's a sink"
	
	w = len(m)
	h = len(m[0])
	
	def is_valid(a, b):
		"is a, b a valid coordinate?"
		return a >= 0 and a < w and b >= 0 and b < h
	
	next = None
	next_el = m[x][y]
	
	x2, y2 = x, y-1
	if is_valid(x2, y2) and m[x2][y2] < next_el:
		next = (x2, y2)
		next_el = m[x2][y2]
	
	x2, y2 = x-1, y
	if is_valid(x2, y2) and m[x2][y2] < next_el:
		next = (x2, y2)
		next_el = m[x2][y2]
	
	x2, y2 = x+1, y	
	if is_valid(x2, y2) and m[x2][y2] < next_el:
		next = (x2, y2)
		next_el = m[x2][y2]
	
	x2, y2 = x, y+1
	if is_valid(x2, y2) and m[x2][y2] < next_el:
		next = (x2, y2)
		next_el = m[x2][y2]
	
	return next

import sys
import copy

data = [x.strip() for x in open(sys.argv[1]).readlines()]

T = int(data[0])
off = 1 # off points to the H, W line in the data

class LetterRef:
	letter = None
	next = None
	
	def set(self, l):
		if self.next is not None:
			self.next.set(l)
		else:
			self.letter = l
	
	def get(self):
		if self.next is not None:
			return self.next.get()
		if self.letter is not None:
			return self.letter
		return '!'

for x in range(T):
	print "Case #%d:" % (x + 1)
	H, W = map(int, data[off].split())
	
	# in retrospect I should probably have done this better :(
	# numpy has 2D arrays, right? should've looked those up before the competition XD
	m = [None] * W
	for y in range(W):
		m[y] = [None] * H
	
	for y in range(H):
		row = map(int, data[off + y + 1].split())
		
		for z in range(W):
			m[z][y] = row[z]
	
	# We have the map, excellent! now do stuff with it
	
	# populate the grid with letter objects
	m2 = copy.deepcopy(m)
	for col in m2:
		for y in range(len(col)):
			col[y] = LetterRef()
	
	for x in range(W):
		for y in range(H):
			n = next_cell(m, x, y)
			if n is not None:
#				print "%d %d -> %d %d" % (x, y, n[0], n[1])
				m2[x][y].next = m2[n[0]][n[1]]
#			else:
#				print "%d %d -> None" % (x, y)
	
	letters = list('abcdefghijklmnopqrstuvwxyz')
	
	for y in range(H):
		for x in range(W):
			if m2[x][y].get() == '!':
				m2[x][y].set(letters.pop(0))
			print m2[x][y].get(),
		print
	off = off + H + 1
