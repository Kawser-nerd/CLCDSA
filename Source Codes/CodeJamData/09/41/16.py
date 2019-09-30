name = 'A'
typ = 'large'
base = name+'-'+typ+'.'
lines = file(base+'in').readlines()

lines = [line.replace('\n','') for line in lines]

T = int(lines[0])

fpos = 1

def swap(data,a,b):
    temp = data[a]
    data[a] = data[b]
    data[b] = temp

def solve(data):
    steps = 0
    for i in xrange(len(data)):
        if data[i] > i:
            j = i+1
            while data[j] > i:
                j+=1
#             print j,i
            steps += j-i
            for j in xrange(j,i,-1):
                swap(data,j,j-1)
#         print data
#     print steps
    return steps

out = file(base+'out','wb')

for case in xrange(1,T+1):
    size = int(lines[fpos])
    fpos += 1
    data = [line.rfind('1') for line in lines[fpos:fpos+size]]
    fpos += size
#     print 'x',data
    out.write('Case #%d: %d\n' % (case, solve(data)))

out.close()
