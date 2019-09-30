f = open('input.txt','rt');
f1 = open('output.txt','wt')
n = int(f.readline())
for i in xrange(n):
    print i
    value = f.readline().strip()
    mem={}
    def probe(i=0,i2=0,i3=0,i5=0,i7=0):
        key = (i,i2,i3,i5,i7)
	global mem,value
        if mem.has_key(key):
	    return mem[key]
	if i==len(value):
	    if (i2==0 or i3==0 or i5==0 or i7==0):
	        return 1
	    else:
	        return 0
	res = 0
        for j in xrange(i+1,len(value)+1):
	    cur = int(value[i:j])
	    res+=probe(j,(i2+cur)%2,(i3+cur)%3,(i5+cur)%5,(i7+cur)%7)
	    res+=probe(j,(-i2-cur)%2,(-i3-cur)%3,(-i5-cur)%5,(-i7-cur)%7)
        mem[key]=res
	return res
    res = probe()
    f1.write("Case #%d: %s\n"%(i+1,res/2))

f.close()
f1.close()
