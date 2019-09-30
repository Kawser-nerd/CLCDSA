#!/usr/bin/python3

'''

Google Code Jam 2013
Qualification Round
Problem D - Treasure

Notes:
	* we have to report the lexicographically smallest/first order of chests necessary to unlock them all
	* if it's impossible, we report that
	* one approach is to attempt all combinations in lexicographic order, and report the first found combination
		* we'd use a recursive function, selecting 1 chest per recursive call
		* without pruning, it would be N! steps
		* but at minimum we'd prune based on available keys, to eliminate impossible orderings
	* we could probably determine as much of an ordering as possible before we began our search
		* eg. chest x must come after chest y because chest y contains the only key for chest x
		* if it weren't for the inclusion of multiple copies of the same key, I think this would boil down to a basic graph connectivity problem?
	* an initial filter could be done based on the total keys available (across all chests and the starting keys) and total keys required (to open all chests)
	* then we have to make sure there is a chain from your starting key leading to every chest
	* based on the points and the number of attempts, the large dataset for this problem is probably ridiculously hard
	
	* I'm going to start coding the input
	* now I have some input code, let's consider how simple our solution for the small dataset can be:
		* N! = 20! = 2432902008176640000
		* that's clearly way more iterations than we can handle
		* so if we're going to do a search as I've roughly outlined above, we really have to filter
		* what about if we take the limited total number of keys into account?
		* hard to reason about this, since the distribution of 40 keys between 20 chests could vary greatly
		* this won't be a good estimate, but let's assume there's 2 keys per chest:
			* .....
	* I'm thinking that it's not important whether we open chest x first or chest y first, if they use different keys
	* the only choices that matter are those involving keys that can open more than 1 chest
	* and it only matters if, at the point of the decision, we have less keys of that type than the number of chests with that lock
	* while the number of keys we have of a given type may change over time, the number of chests of a type will not, so if we have enough keys for all of them, there's no decision to be made
		* in such cases, we just open the chests in the indicated lexicographic ordering, and know that if that ordering didn't work, no other ordering is going to work either
	* can we simplify and extract the essence of this realisation?
	* what about transitive closures and stuff........
		* can we simplify a whole group of related chests down to a single chest
			* like eg. if opening chest x leads to key y, which leads to only chest y, which leads to key z, then we can just consider chest x to give us key z
			* but such situations aren't guaranteed to be present - we have to cater to the worst case, right?  or at least the average case (whatever that means in this context)
			* furthermore, since you can only open a given chest once, an expansion may become invalid in a situation where one of the involved chests is already open
	* I'm thinking of an analogy to parsing...
		* keys are like non-terminals
			* they may expand to a series of keys
			* (although order doesn't matter)
		* chests are like productions
			* (although you can only apply each one a maximum of once)
			* (and your goal is to apply each of them exactly once)
		* clearly there is never a problem opening a chest if it guarantees you will get back the key used to open it
			* but note that we still have the lexicographic ordering constraint, so if there are other chests that could have opened with that key, without resulting in IMPOSSIBLE, they may have to open first
		* equally, there is never going to be a problem opening a chest if you already have more (or equal) keys of that type than there are chests
	
	* I'm wondering if I should risk just implementing a naive recursive search solution, without any strong evidence it will be fast enough?
		* that 20! is scary
		* but with filtering based on limited keys, that's unlikely to happen, right?
		* let's see... with 1 chest that can never be opened, we'd potentially do at least a full 19! iterations?
		* at least I can try it on the sample input and output
	
	* I'm actually quite worried about this initial version not working for the small dataset...
	* but I guess if it fails, I can try again... so I shouldn't have worried so much
	
	* I'm thinking that so long as you always hold onto 1 key of a given type, you can never be blocked
		* this is because there is no situation where you need to open chest a *and* chest b to get a particular key
		* basically, whenever you are ready to open a chest (in the lexicographic ordering) for which you have only a single key, and for which there is more than 1 chest remaining with that key, you have to ask yourself:
			* does this chest potentially lead to more instances of this key?
				* work with shut chests only
				* of course you include keys directly in that chest
				* you also include keys that will become accessible
			* but... it's not about the last key in your personal set of keys, but the last key accessible without using the key you are running out of
			* and we don't care about the total number of keys - we only care about reaching 1 additional instance of the key
	* so the only time a choice becomes critical (and therefore important enough to disrupt the lexicographic ordering) is when you have only 1 key remaining of that type
	
	* initially, calculate the requirements for each key type - ie. the number of chests requiring that key, in a dict
		* so long as we're doing that, we might as well calculate the key supplies in a similar way, and compare, for a quick filtering?
	
	* we need a function "reachable_keys", which calculates the quantities of keys we can obtain access to based on our current keys
	* if a chest we want to open uses a key for which its reachable_keys entry is 1, we have to consider delaying opening of that chest until we encounter more instances of that key
	
	* wait... I think we need something more like "keys_reachable_without_using_key_x"
	
	* if we consume our last instance of key x, then we cannot open all chests unless either:
		* there are no more chests requiring key x
		* a new instance of key x is reachable after we consumed our instance of key x
	
	* so how does the reachability calculation work?
		* basically, we just calculate what we could reach if using a key didn't consume it, right?
	
	* so we're about to open chest c:
		* temporarily/speculatively:
			* remove the key used to open chest c, which we'll call key k
			* add the keys found in chest c
			* mark chest c as opened (so it can't be opened again)
			* determine reachable keys from this new state
			* if a chest requiring key k exists and is still shut, and key k is no longer reachable, then we cannot open this chest and must instead move onto the next one
			* otherwise, we can and must open this chest (to get the ordering right)
	
	* okay, I got the small dataset working with the above algorithm...
		* but now I have to ask myself: what are they going to throw at me with the large dataset?
		* did I already overcome the obstacles that were going to be posed in the large dataset?
		* perhaps there's a middle strategy that would solve the small but not the large, and I already went one better than it?
		* seriously, I'm thinking this must be the case, because I really think my current algorithm is pretty nifty
		* I'm going to go straight for the large dataset now... if it's wrong, well... I've already spent a lot of time on this problem and I don't want to waste more on the off chance that I'm incorrect
		* I'm at 515... if this works, I'll be at 72 or less, I guess...
		* I'll go for it

'''

import sys
import time

timeit = 1
debugv = 0

def main():
	T = int(sys.stdin.readline())
	for case in range(1,T+1):
		doCase(case)

def doCase(case):
	K, N = [int(n) for n in sys.stdin.readline().split()]
	key_list = [int(n) for n in sys.stdin.readline().split()]
	if len(key_list) != K: raise Exception("expected {} keys but found {}".format(K, len(key_list)))
	keys = dict()  # <<< I think I'm shadowing a keyword here?  maybe fix later...
	for k in key_list:
		# <<< I might have to learn more about python dicts... I miss being able to just say (effectively) keys[k]++ and get the desired result whether the key was already there or not
		if not k in keys: keys[k] = 0
		keys[k] += 1
	chest_locks = [None] * N
	chest_contents = [None] * N
	# I probably would have arranged the data more like chests[i].lock, chests[i].keys[j], if I had a bit more python experience
	for i in range(N):
		line = [int(n) for n in sys.stdin.readline().split()]
		chest_locks[i] = line[0]
		key_count = line[1]
		chest_contents[i] = line[2:]
		if len(chest_contents[i]) != key_count: raise Exception("expected {} keys in chest, but found {}".format(key_count, len(chest_contents[i])))
	
	def get_reachable_keys(shut, keys):
		keys = keys.copy()
		shut = shut[:]
		while 1:
			opened = False
			for ci in shut:
				# <<< note that the check for at least 1 key is for safety, in case I made a mistake elsewhere
				if (chest_locks[ci] in keys) and (keys[chest_locks[ci]] >= 1):
					# <<< what effect does this have on the loop iterating over shut?
					# note that for the purpose of this routine, we don't decrement keys
					opened = True
					shut.remove(ci)
					for k in chest_contents[ci]:
						if not k in keys: keys[k] = 0
						keys[k] += 1
					# <<< we break mainly to avoid potential problems from altering the list we're iterating over
					break
			if not opened:
				break
		
		return keys
		
		
	
	def okay_to_open(shut, keys, ci):
		# check the chest hasn't been opened already
		# (what the heck, it won't hurt to much to do this simple check again)
		if not ci in shut: return False
		
		key_type = chest_locks[ci]
		
		# check that we have the key
		# this check is expected by the caller, thus necessary
		if not (key_type in keys and keys[key_type] >= 1):
			return False
		
		# we never have to worry unless we're about to use our final key
		if keys[key_type] >= 2:
			return True
		
		# we have exactly 1 instance of the key, and we're about to use it up
		
		new_shut = shut[:]
		new_shut.remove(ci)
		
		# check if the key is required for another unopened chest
		if not key_type in [chest_locks[cix] for cix in new_shut]:   # <<< unsure about python scoping, so renamed the ci variable for safety
			return True
		
		# copy the keys dict and eliminate 0-value keys and the key we're now reducing to 0 value
		new_keys = {k: q for (k, q) in keys.items() if q > 0 and k != key_type}
		
		# add the keys from ci
		for k in chest_contents[ci]:
			if not k in new_keys: new_keys[k] = 0
			new_keys[k] += 1
		
		reachable_keys = get_reachable_keys(new_shut, new_keys)
		
		if key_type in reachable_keys:
			return True
		else:
			return False
	
	def search(opened, shut, keys):
		if len(shut) == 0: return opened
		
		for ci in shut:
			if okay_to_open(shut, keys, ci):
				# since this is now tail recursion, we don't technically have to make copies of any of this data anymore, or pass it as arguments
				# but for now I'd like to avoid making changes that may not be necessary
				# also note that we could exit the loop before making the recursive call
				# and I suppose we could eliminate the recursion completely, too...
				key_type = chest_locks[ci]
				new_shut = shut[:]
				new_shut.remove(ci)
				new_opened = opened + [ci]
				new_keys = keys.copy()
				new_keys[key_type] -= 1
				for k in chest_contents[ci]:
					if not k in new_keys: new_keys[k] = 0
					new_keys[k] += 1
				
				# note that we only ever recurse once, so we don't get N! runtime
				return search(new_opened, new_shut, new_keys)
		return None
	
	result = search([], [chest for chest in range(N)], keys)
	
	debug("{}\n".format(result))
	sys.stdout.write("Case #{}: {}\n".format(case, 'IMPOSSIBLE' if (result == None) else (' '.join([str(ci + 1) for ci in result]))))


def debug(m):
	if debugv:
		sys.stderr.write(m)

if __name__ == '__main__':
	startTime = time.clock()
	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime))

