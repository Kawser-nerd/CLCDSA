inp_file=file("A-small.in")
out_file=file("A-small.out","w")

def solve(line):
    n,A,B,C,D,x0,y0,M=[int(c1) for c1 in line.split(" ")]
    trees=[]
    X=x0;Y=y0
    trees.append((X,Y))
    for i in range(1,n):
        X = (A * X + B) % M
        Y = (C * Y + D) % M
        trees.append((X%3,Y%3))
    res=0
    for t1 in range(len(trees)):
        for t2 in range(t1+1,len(trees)):
            for t3 in range(t2+1,len(trees)):
                if not (trees[t1][0]+trees[t2][0]+trees[t3][0])%3:
                    if not (trees[t1][1]+trees[t2][1]+trees[t3][1])%3:
                        res+=1
    return str(res)

num=int(inp_file.readline())
for case in range(num):
    line=inp_file.readline()
    out_file.write("Case #%s: "%(case+1)+solve(line)+"\n")
inp_file.close()
out_file.close()
