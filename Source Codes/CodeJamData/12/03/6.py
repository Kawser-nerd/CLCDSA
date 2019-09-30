import time

def recyclelist(param):
    list = set([])
    x = str(param)
    for i in range(len(x)):
        if x[0] != '0':
            list.add(int(x))
        x = x[1:] + x[0]
    return (min(list), list)
    


recycleSets = [None for i in range(2000000)]
start = time.time()
for i in range(1, 2000001):
    if (recycleSets[i-1] == None):
        tup = recyclelist(i)
        for j in tup[1]:
            if j <= 2000000:
                recycleSets[j-1] = tup
print time.time() - start
start = time.time()

with open('C-large.in', 'r') as fin:
#with open('input.txt', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        for i in range(1, numcases+1):
            line = [int(j) for j in fin.readline().split()]
            a = line[0]
            b = line[1]
            
            used = set({})
            count = 0
            
            for j in range(a, b+1):
                reSet = recycleSets[j-1]
                thiscount = 0
                if reSet[0] not in used:
                    for k in reSet[1]:
                        if (k >= a) and (k <= b):
                            thiscount += 1
                    '''if (thiscount > 1):
                        print(str(thiscount) + str(reSet))'''
                    used.add(reSet[0])
                count += thiscount*(thiscount-1)/2
            
            
            fout.write("Case #")
            fout.write(str(i))
            fout.write(": ")
            fout.write(str(count))
            fout.write('\n')
print (time.time() - start)