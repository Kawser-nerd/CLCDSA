import os,sys,fileinput
debug = False
def getline():
	R= sys.stdin.readline()
	R = R.replace("\n","")
	R = R.replace("\r","")
	return R.strip()

T = int(getline())
cache = {}
d = set()
sys.setrecursionlimit(29999)

def examine(S,errorlimit):
	global cache, d
	if len(S) == 0:
		return 0
	key = S + "_" + str(errorlimit)
	if key in cache:
		return cache[key]
	if S in d:
		return 0
	R = 1e99
	for w in d:
		if S.startswith(w):
			lw = len(w)
			rest = S[lw:]
			R = min( R , examine( rest, errorlimit ) )
	cache[key] = R
	return R

for w in open("garbled_email_dictionary.txt").readlines():
	d.add(w.strip())
if debug:
	print("Max length is: %d" % max([ len(x) for x in d ]) )
tree = {}
tree["id"]="ROOT"
EOF="$"
for w in d:
	t = tree
	partialword = ""
	for ch in w:
		partialword += ch
		if not ch in t:
			t[ch] = {}
			t[ch]["id"] = partialword
		t = t[ch]
	t[EOF] = {}
	t[EOF]["id"] = w

if debug:
	print ("Read %d words" % len(d))

feedcache={}

def feedletter(s, pos, errorafterpos , t):
	global tree, feedcache
	if pos == len(s):
		if EOF in t:
			return 0
		else:
			return 1e99
		
	ch = s[pos]
	key = "%d-%d-%s" % (pos, errorafterpos, t["id"])
	if key in feedcache:
		return feedcache[ key ]

	if debug:
		print("Key: %s" % key)

	R = 1e99
	for x in t.keys():
		if x == "id":
			continue
		elif x == EOF:
			# END OF WORD, start a new one
			R = min(R, feedletter( s, pos, errorafterpos, tree ) )
		elif ch == x:
			# add with no error
			R = min(R, feedletter( s, pos + 1, errorafterpos, t[ch] ) )
		else:
			# Can perform an error ?
			if pos >= errorafterpos:
				R = min(R, 1 + feedletter( s, pos + 1, pos + 5, t[x] ) )
	feedcache[ key ] = R
	return R

	
for t in range(T):
	S = getline()
	cache = {}
	feedcache = {}
	result = feedletter( S, 0, 0, tree )
	
	print ( "Case #%d: %d" % ( t+1, result) )
