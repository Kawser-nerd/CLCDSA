f=open("data","r")
allmins=eval(f.read())
f.close()

for case in range(input()):
    print "Case #"+str(case+1)+":",
    bases=tuple(map(int,raw_input().split()))
    print allmins[bases]
