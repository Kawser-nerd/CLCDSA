import commands
t = input()

for c in range(1, t+1) :
        n = input()
        s = commands.getoutput("""echo 'scale=2000
        (3+sqrt(5))^%d' | bc""" % n)
        t = "000" + s.split(".")[0]
        print "Case #%d: %s" % (c, t[-3:])
