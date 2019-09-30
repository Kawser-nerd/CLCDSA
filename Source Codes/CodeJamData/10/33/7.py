#!/usr/bin/env python

class clip():
    def __init__(self, value):
        self.value = value
        self.right = 0
        self.down = 0

def workright(matrix,m,n):
    for i in range(m):
        if matrix[i][-1].value == -1:
            matrix[i][-1].right = 0
        else:
            matrix[i][-1].right = 1
        for j in range(n-2, -1, -1):
            if matrix[i][j].value == -1:
                matrix[i][j].right = 0
                continue
            if matrix[i][j].value == matrix[i][j+1].value:
                matrix[i][j].right = 1
            else:
                matrix[i][j].right = matrix[i][j+1].right + 1
               
def workdown(matrix,m,n):
    for j in range(n):
        if matrix[-1][j].value == -1:
            matrix[-1][j].down = 0
        else:
            matrix[-1][j].down = 1
        for i in range(m-2, -1, -1):
            if matrix[i][j].value == -1:
                matrix[i][j].down = 0
                continue
            if matrix[i][j].value == matrix[i+1][j].value:
                matrix[i][j].down = 1
            else:
                matrix[i][j].down = matrix[i+1][j].down + 1
    
def countn(matrix,size,m,n):
    count = 0
    for i in range(m):
        for j in range(n):
            if (matrix[i][j].right >= size and \
                    matrix[i][j].down >= size and i+size <= m):
                flag = True
                for k in range(size):
                    if matrix[i+k][j].right < size:
                        flag = False
                        break
                if flag:
                    count += 1
                    #if size == 1:
                        #print 'debug',i,' ',j
                    for k in range(size):
                        for l in range(size):
                            matrix[i+k][j+l].value = -1
                    workright(matrix,m,n)
                    workdown(matrix,m,n)
                    
    return count

def main():
    fin = open('small.in','r')
    fout = open('small.out','w')
    tn = int(fin.readline())
    for test in range(tn):
        m,n = fin.readline().split(' ')
        m = int(m)
        n = int(n)
        matrix = []
        for i in range(m):
            data = fin.readline()[:-1]
            matrix.append([])
            for char in data:
                matrix[-1].append(clip((int(char,16) & 8)>>3))
                matrix[-1].append(clip((int(char,16) & 4)>>2))
                matrix[-1].append(clip((int(char,16) & 2)>>1))
                matrix[-1].append(clip((int(char,16) & 1)))

        workright(matrix,m,n)
        workdown(matrix,m,n)

        #for line in matrix:
            #for item in line:
                #print item.down
            #print

        final = []
        for size in range(min(m,n),0,-1):
            ans = countn(matrix,size,m,n)
            if ans != 0:
                final.append([size,ans])
        fout.write('Case #%d: %d\n' % (test+1, len(final)))
        for item in final:
            fout.write('%d %d\n' % (item[0],item[1]))
        #for line in matrix:
            #for item in line:
                #print item.value
            #print
            

    fin.close()
    fout.close()

if __name__=='__main__':
    main()
