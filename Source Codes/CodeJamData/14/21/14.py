T = input()

def encode(input_string):
    count = 1
    prev = ''
    lst = []
    for character in input_string:
        if character != prev:
            if prev:
                entry = (prev,count)
                lst.append(entry)
                #print lst
            count = 1
            prev = character
        else:
            count += 1
    else:
        entry = (character,count)
        lst.append(entry)
    return lst
 

def moves(l):
	m = 100000000
	for i in range(200):
		m = min(m, sum(abs(x - i) for x in l))
	return m

for case in range(1, T + 1):
	N = input()
	strs = [raw_input() for i in range(N)]
	# print strs
	uniq = set(''.join(x[0] for x in encode(s)) for s in strs)
	enc = [[x[1] for x in encode(s)] for s in strs]
	# print enc
	ans = 'Fegla Won'
	if len(uniq) == 1:
		bypos = [[l[i] for l in enc] for i in range(len(enc[0]))]
		ans = sum(moves(l) for l in bypos)

	print "Case #%d:" % case, ans