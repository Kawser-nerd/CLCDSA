#!/usr/bin/env pypy

import sys
from collections import Counter, defaultdict

class Chest:
	def __init__(self, key, vals):
		self.k = key
		self.v = vals

	def __str__(self):
		return "Chest(key=" + str(self.k) + ",vals=" + str(self.v) + ")"
	def __repr__(self):
		return str(self)
	def __hash__(self):
		return (self.k.__hash__()<< 5) ^ self.v.__hash__()
	def __eq__(self, other):
		return other.k == self.k and other.v == self.v

def readline():
	s = raw_input().strip()
	while s == "":
		s = raw_input().strip()
	return s

def readvals():
	return map(int, readline().split())


def remove_unused(chest, used_keys):
	return Chest(chest.k, tuple(k for k in chest.v if k in used_keys))

def remove_unneeded(chest, keys_needed):
	return Chest(chest.k, tuple(k for k in chest.v if keys_needed[k] > 0))

def memo2(f):
	memo_cache = {}
	# cache a 2 parameter function
	def g(a, b):
		key = (a,b)
		if key in memo_cache:
			return memo_cache[key]
		memo_cache[key] = val = f(a,b)
		return val
	return g

@memo2
def exist_unobtainable_keys(keys, chests):
	"""
	Check if there is any type of key which cant be obtained
	This might need better detection of cycles...
	Be careful with this
	"""
	keys_held = set(keys)
	keyset = set(c.k for c in chests)
	can_obtain = {k: k in keys_held for k in keyset}
	keep_going = True
	while keep_going:
		keep_going = False
		if all(can_obtain.values()):
			return False

		next_chests = []
		for chest in chests:
			if not can_obtain[chest.k]:
				next_chests.append(chest)
				continue
			keep_going = True
			for k in chest.v:
				if k != chest.k:
					can_obtain[k] = True
		chests = tuple(next_chests)
	return True

def common_remove_useless_keys(keys, chests):
	"""
	Removes the keys from chests and hand that don't have any influence on the solution
	Returns a pair (new_keys, new_chests), or (None, None) if the problem is unsolvable
	"""

	# Remove keys that cannot open any locks
	keyset = set(c.k for c in chests)
	keys = tuple(k for k in keys if k in keyset)
	chests = tuple(remove_unused(chest, keyset) for chest in chests)

	# Count the number of keys that you still need to take from a chest
	# to unlock another chest
	keys_needed = Counter()
	for c in chests:
		keys_needed[c.k] += 1

	for k in keys:
		keys_needed[k] -= 1

	# Only keep keys if the number to unlock is greater than number held
	chests = tuple(remove_unneeded(chest, keys_needed) for chest in chests)

	# Next, count the number of keys in chest/hand versus total
	# This seems wrong, actually
	key_balance = keys_needed # keys needed - keys existing
	keys_needed = None

	for c in chests:
		for k in c.v:
			key_balance[k] -= 1

	# Check if there are more keys needed than required anywhere(may be redundant)
	if any(count > 0 for count in key_balance.values()):
		return (None, None)

	if exist_unobtainable_keys(keys, chests):
		return (None, None)

	return (keys, chests)


def exists_solution_helper(keys, chests):
	keys_held = set(keys)
	key_balance = Counter()
	for k in keys:
		key_balance[k] -= 1
	for c in chests:
		key_balance[c.k] += 1
	for i,c in enumerate(chests):
		# You can obviously take one of these
		if key_balance[c.k] <= 0:
			new_keys, new_chests = remove_chest(keys, chests, i)
			solution_exists = exists_solution(new_keys, new_chests)[2]
			return solution_exists

	tried = set()
	for i, c in enumerate(chests):
		k = c.k
		if k in keys_held and c not in tried:
			new_keys, new_chests = remove_chest(keys, chests, i)
			exists = exists_solution(new_keys, new_chests)[2]
			if exists:
				return True
			tried.add(c)
	return False


def exists_solution(keys, chests):
	"""
	Returns (simplified keys, simplified chests, solution exists)

	Used to optimize best_solution in failure cases
	"""
	if len(chests) == 0:
		return keys, chests, True

	keys, chests = common_remove_useless_keys(keys, chests)
	if keys is None:
		return keys, chests, False

	return keys, chests, exists_solution_helper(keys, chests)

def remove_chest(keys, chests, i):
	"""
	Remove the i'th chest
	return (new_keys, new_chests)
	"""
	c = chests[i]
	j = keys.index(c.k)
	return (keys[:j] + keys[j+1:] + c.v,
			chests[:i] + chests[i+1:])

@memo2
def best_solution(keys, chests):
	"""
	Returns the best solution as
	a tuple of n unique integers from 0..n-1

	If no solution exists, returns None
	"""
	if len(chests) == 0:
		return ()

	keys, chests, exists = exists_solution(keys, chests)

	#keys, chests = common_remove_useless_keys(keys, chests)

	if not exists:
		return None

	keys_held = set(keys)

	tried = set()
	for i, c in enumerate(chests):
		k = c.k
		if k in keys_held and c not in tried:
			new_keys, new_chests = remove_chest(keys, chests, i)
			sol = best_solution(new_keys, new_chests)
			if sol is not None:
				return (i,) + tuple(x if x < i else x+1 for x in sol)
			tried.add(c)

def verify_solution(keys, chests, sol):
	if len(sol) != len(chests):
		raise RuntimeError("Invalid length")
	if set(sol) != set(range(len(chests))):
		raise RuntimeError("Invalid set of values")
	for i in sol:
		c = chests[i]
		if c.k not in keys:
			raise RuntimeError("Could not find key {0} in chest {1}".format(c.k, i))
		j = keys.index(c.k)
		keys = keys[:j] + keys[j+1:] + c.v
	#Successful!
	return True


def solve():
	K, N = readvals()
	start_keys = tuple(readvals())
	chests = []
	for i in range(N):
		vals = tuple(readvals())
		t_i, k_i = vals[:2]
		chests.append(Chest(t_i, vals[2:2+k_i]))
	chests = tuple(chests)

	sol = best_solution(start_keys, chests)
	if sol is None:
		return "IMPOSSIBLE"
	verify_solution(start_keys, chests, sol)
	return " ".join(str(x+1) for x in sol)

if __name__ == "__main__":
	T = int(readline())
	for i in range(T):
		sol = solve()
		print("Case #{0}: {1}".format(i+1, sol))
