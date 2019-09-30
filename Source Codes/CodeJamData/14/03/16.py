def solve(m,n, squares):
    if squares ==1:
        return [[True if x==0 and y==0 else False for x in range(m)] for y in range(n)]

    if m==1:
        return [[True if y<squares else False for x in range(m)] for y in range(n)]

    if n==1:
        return [[True if x < squares else False for x in range(m)] for y in range(n)]

    # if m==2 and squares ==2:
    #     return [[True if y==0 else False for x in range(m)] for y in range(n)]

    # if n==2 and squares ==2:
    #     return [[True if x ==0 else False for x in range(m)] for y in range(n)]


    for i in range(2,m+1):
        for j in range(2,n+1):
            #print i,j
            border = squares - (i*j)
            if border ==0:
                #print "%d by %d with no border" % (i, j)
                return build(m,n,i,j,0,0)
            side1 = j if i - m < 0 else 0
            side2 = i if j - n < 0 else 0

            #print side1, side2
            if border > side1 + side2: continue
            for alloc in range(border+1):
                if alloc <= side1 and border-alloc <= side2 and alloc != 1 and border-alloc != 1:
                    #print "%d by %d with additional %d, %d" % (i,j,alloc, border-alloc)
                    return build(m,n,i,j,border-alloc, alloc)

def build(m,n,i,j,a,b):
    return [[True if (x< i and y < j) or (x== i and y < b ) or (x < a and y ==j ) else False for x in range(m)] for y in range(n)]

def show(x):
    pre = [["." if val else "*" for val in line] for line in x]
    pre[0][0] = "c"
    for line in pre:
        print "".join(line)

f = open('input.in', 'r')
data = f.read().split('\n')

size = int(data[0])
for x in range(size):
    print "Case #%d:" % (x +1)
    line = map(int,data[x+1].split(" "))
    #print line
    a, b, free = line[0], line[1], line[0]*line[1] - line[2]
    if solve(a,b,free) is None:
        print "Impossible"
    else:
        show(solve(b,a,free))

