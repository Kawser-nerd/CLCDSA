#!/usr/bin/env python3

in_pattern='''y qee
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv'''

out_pattern='''a zoo
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up'''

map ={}
for (i,j) in zip(in_pattern,out_pattern):
	map[i]=j

import string

for dest in string.ascii_lowercase:
	if dest not in map.values():
		for source in string.ascii_lowercase:
			if source not in map:
				map[source]=dest

k = int(input())
for i in range(k):
	text = input()
	print("Case #",i+1,": ",''.join([map[i] for i in text]),sep='')
