import re
'''
I don't get it.
How can we already have their alphabet AND find out that they've been sending messages for 10 years.
Did they visit us? Why have they been sending messages in the first place?
Did we visit them? What, by accident? With hyper-speed starships?
Do we have a time machine? Why the hell do we care about aliens if we have a damn Time Machine?
Do we have a ten-year record of every single random radio transmission that's hit the earth?

I call BS.
'''

text = open("A.in","rt").readlines()
outfile = open("A.out","wt")
l,d,n = [int(_) for _ in text[0].split(" ")]
words = [word.strip("\n") for word in text[1:1+d]]
tests = [test.strip("\n").replace("(","[").replace(")","]") for test in text[1+d:]]

for ind, test in enumerate(tests):
    correct = [word for word in words if re.match(test, word)]
    print "Case #%s: %s" % (ind+1, len(correct))
    outfile.write("Case #%s: %s\n" % (ind+1, len(correct)))


