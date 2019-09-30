from __future__ import division
import sys
import math
from collections import deque
import itertools

from collections import namedtuple

sys.stdin = open('small.in')
debug = open('debug.txt', 'w')
sys.stdout = open('small.out', 'w')

Building = object()
Goal = object()
MetGoal = object()
DeadWater = object()

directions = [
	(0, 1),
	(1, 0),
	(0, -1),
	(-1, 0)
]

left_of = {}
right_of = {}
behind = {}

for i in range(4):
	straight = directions[i]
	right = directions[(i + 1) % 4]
	back = directions[(i + 2) % 4]
	left = directions[(i + 3) % 4]

	right_of[straight] = right
	behind[straight] = back
	left_of[straight] = left

class River(object):
	def __init__(self, w, h, buildings):
		self.w = w
		self.h = h
		self.grid = grid = {}

		for x in range(w):
			for y in range(h):
				self.grid[x, y] = None

		for x in range(w):
			self.grid[x, h] = Goal
			self.grid[x, -1] = Building
			self.grid[x, -2] = Building

		for y in range(-1, h):
			self.grid[-1, y] = Building
			self.grid[w, y] = Building

		for x0, y0, x1, y1 in buildings:
			for x in range(x0, x1 + 1):
				for y in range(y0, y1 + 1):
					self.grid[x, y] = Building

	def __str__(self):
		return "<River\n\t{disp}\n>".format(
			disp='\n\t'.join(
				'|' + ''.join(
					'#' if self.grid[x, y] is Building else
					'.' if self.grid[x, y] is DeadWater else
					' ' if self.grid[x, y] is None else
					str(self.grid[x, y] % 10)
					for x in range(self.w)
				) + '|'
				for y in range(-1, self.h)
			)
		)

	def solve_stream(self, which):
		def try_move(pos, dir):
			next_pos = (pos[0] + dir[0], pos[1] + dir[1])
			if self.grid[next_pos] is Goal:
				self.grid[next_pos] = MetGoal
				return True

			elif self.grid[next_pos] is None:
				self.grid[next_pos] = which
				try:
					next_step = (
						try_move(next_pos, left_of[dir]) or
						try_move(next_pos, dir) or
						try_move(next_pos, right_of[dir])
					)
				except RuntimeError:
					print self
					raise
				if not next_step:
					self.grid[next_pos] = None

				return next_step

			else:
				return False

		try_move(
			pos = (which, -1),
			dir = (0, 1)
		)

	def solve_stream_norec(self, which):
		pos = (which, -1)
		dir = (0, 1)

		def add_pos(d):
			return (pos[0] + d[0], pos[1] + d[1])

		while True:
			for next_dir in [left_of[dir], dir, right_of[dir], behind[dir]]:
				next_pos = (pos[0] + next_dir[0], pos[1] + next_dir[1])

				# done
				if self.grid[next_pos] is Goal:
					self.grid[next_pos] = MetGoal
					return True

				# we can tread on this cell
				elif self.grid[next_pos] is None:
					self.grid[next_pos] = which

					pos = next_pos
					dir = next_dir
					break

				elif self.grid[next_pos] == which:
					self.grid[pos] = DeadWater
					pos = next_pos
					dir = next_dir
					break

			# no
			else:
				return False

	def solve(self):
		for x in range(self.w):
			self.solve_stream_norec(x)


def solve(w, h, buildings):
	r = River(w, h, buildings)
	r.solve()
	print >> debug, r
	return r.grid.values().count(MetGoal)

t = int(raw_input())

for i in range(t):
	w, h, b = map(int, raw_input().split())
	buildings = [
		map(int, raw_input().split())
		for _ in range(b)
	]
	print "Case #{}: {}".format(i+1, solve(w, h, buildings))
