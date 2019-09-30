f = open('input.txt','rt');
f1 = open('output.txt','wt')
n = int(f.readline())
for i in xrange(n):
    p,k,l = map(int,f.readline().split(' '))
    d = map(int,f.readline().split(' '))
    if p*k<l:
        f1.write("Case #%d: Impossible\n"%(i+1))
    else:
        d.sort(lambda x,y:cmp(y,x))
	step = 0
	press = 0
	res = 0
	for j in d:
	    step = step%k
	    if step==0:
	        press+=1
	    res+=j*press
	    step+=1
        f1.write("Case #%d: %s\n"%(i+1,res))

f.close()
f1.close()
