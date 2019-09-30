# Google Code Jam 2015, Round 1A
# Problem C. Logging
# Lance C. Simons

from math import atan2, pi

def collinear((x0,y0), (x1,y1), (x2,y2)):
	# dy1/dx1 == dy2/dx2  -->  dy1*dx2 == dy2*dx1
	lx = x1-x0
	ly = y1-y0
	rx = x2-x1
	ry = y2-y1
	return ly*rx == ry*lx

def angle((x0,y0), (x1,y1)):
	return atan2(y1-y0, x1-x0)


def squirrel_radar(me, tree_positions, tree_angles, tree_IDs):

	trees = len(tree_angles)
	def at(i):
		rotations = i / trees
		return tree_angles[i % trees] + (2 * pi * rotations)

	most_of_a_turn = pi * .95
	full_turn = pi

	# Can be optimized out, but I need it to think
	# The # of trees strictly between the tree at angle tree_angles[i] and tree_angles[i]+180deg
	# return min
	counts = [len(tree_angles)] * len(tree_angles)

	left_idx = 0
	left = at(left_idx)

	right_idx = 1
	while at(right_idx) - left < most_of_a_turn:
		right_idx += 1	
	while at(right_idx) - left < full_turn and not collinear(tree_positions[tree_IDs[left_idx]], tree_positions[me], tree_positions[tree_IDs[right_idx % trees]]): 
		right_idx += 1

	counts[0] = right_idx - left_idx - 1

	for i in range(1, len(tree_angles)):
		left_idx += 1
		left = at(left_idx)

		while at(right_idx) - left < most_of_a_turn:
			right_idx += 1
		while at(right_idx) - left < full_turn and not collinear(tree_positions[tree_IDs[left_idx]], tree_positions[me], tree_positions[tree_IDs[right_idx % trees]]):
			right_idx += 1			
		counts[i] = right_idx - left_idx - 1	

	return max(0, min(counts))

def squirrels(tree_positions):

	if len(tree_positions) <= 3:
		return [0] * len(tree_positions)

	squirrel_surveys = []

	for i in range(len(tree_positions)):

		# each tree keeps two lists:
		# 	angles[i] is the heading toward tree i
		#   IDs[i] is the ID of the tree in direction[i]

		angle_IDs = []
		for j in range(len(tree_positions)):
			if i != j:
				angle_IDs.append( (angle(tree_positions[i], tree_positions[j]), j) )
		angle_IDs.sort()

		angles, IDs = zip(*angle_IDs)
		squirrel_surveys.append( squirrel_radar(i, tree_positions, angles, IDs) )

	return squirrel_surveys


def go(infilename, outfilename):
	inf = open(infilename, "r")
	outf = open(outfilename, "w")
	runs = int(inf.next().strip())
	for i in range(runs):
		trees = int(inf.next().strip())
		tree_positions = [map(int, inf.next().strip().split()) for t in range(trees)]
		outf.write("Case #%d:\n%s\n" % (i+1, "\n".join(map(str, squirrels(tree_positions)))))

if __name__ == "__main__":
	import sys
	go(sys.argv[1], sys.argv[1].replace(".in", ".out"))