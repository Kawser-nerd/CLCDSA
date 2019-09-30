inp_file=file("B-small.in")
out_file=file("B-small.out","w")

def solve(line):
    A,B,P=[int(c1) for c1 in line.split(" ")]
    numbers=range(A,B+1)
    sets=range(B-A+1)
    for c1 in primes:
        if c1<P:continue
        if c1>B/2+1:break
        same=[]
        for c2 in numbers:
            if not c2%c1:same.append(c2-A)
        sets=merge_sets(sets,same)
    counted=[]
    c2=0
    for c1 in sets:
        if not c1 in counted:
            counted.append(c1)
            c2+=1
    return str(c2)

def merge_sets(sets,same):
    to_change=[sets[c1] for c1 in same]
    for c1 in range(len(sets)):
        if sets[c1] in to_change:
            sets[c1]=to_change[0]
    return sets

p_file=file("primes1000.txt")
primes=[int(c1) for c1 in p_file.read().split("\n")]
p_file.close()
num=int(inp_file.readline())
for case in range(num):
    line=inp_file.readline()[:-1]
    out_file.write("Case #%s: "%(case+1)+solve(line)+"\n")
inp_file.close()
out_file.close()
