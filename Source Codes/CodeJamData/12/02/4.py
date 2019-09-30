with open('B-large.in', 'r') as fin:
#with open('input.txt', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        for i in range(1, numcases+1):
            line = [int(j) for j in fin.readline().split()]
            surprising = line[1]
            minscore = line[2]
            
            oknum = 0
            needsSurprising = 0
            for j in line[3:]:
                d = j/3
                m = j%3
                if m == 0:
                    if d >= minscore:
                        oknum += 1
                    elif d >= minscore - 1 and d > 0:
                        needsSurprising += 1
                elif m == 1:
                    if d >= minscore-1:
                        oknum += 1
                elif m == 2:
                    if d >= minscore-1:
                        oknum += 1
                    elif d >= minscore -2:
                        needsSurprising += 1
            
            
            fout.write("Case #")
            fout.write(str(i))
            fout.write(": ")
            fout.write(str(oknum + min(surprising, needsSurprising)))
            fout.write('\n')