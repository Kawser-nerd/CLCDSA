import sys

with open(sys.argv[1]) as f:
    lines = f.readlines()

T = int(lines[0],10)
for tt, l in enumerate(lines[1:]):
    pancakes = l.strip()
    done = False
    flips = 0
    while 1:
        #print pancakes
        index = pancakes.rfind("-")
        if index == -1:
            break
        flips += 1
        new_cakes = ""
        for i in xrange(index+1):
            if pancakes[i] == "+":
                new_cakes += "-"
            elif pancakes[i] == "-":
                new_cakes += "+"
            else:
                raise Exception("wtf")
        
        pancakes = new_cakes + pancakes[index+1:]
        
    print ("Case #%d:" % (tt+1)), flips

        

