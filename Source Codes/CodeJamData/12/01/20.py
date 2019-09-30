
import sys

sampin = "y qee ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
sampout= "a zoo our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"

chars = " abcdefghijklmnopqrstuvwxyz"

m = {}
ileft = set(chars)
oleft = set(chars)

for i,o in zip(sampin, sampout):
	m[i] = o
	ileft.discard(i)
	oleft.discard(o)
ilast = list(ileft)[0]
olast = list(oleft)[0]
m[ilast] = olast
#lmap = ''.join([m[c] for c in chars])
#print lmap

T = int(raw_input())

for t in range(1,T+1):
	line = raw_input()
	print "Case #" + str(t) + ": " + ''.join([m[c] for c in line])
