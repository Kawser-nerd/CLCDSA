'''
Created on May 23, 2010

@author: Darren
'''

if __name__ == "__main__":
    f = open("A-large.in", "r")
    fout = open("A-large.out", "w")
    # T, the number of test cases in the input file
    T = int(f.readline())
    for i in xrange(T):
        N = int(f.readline())
        a_list = []
        b_list = []
        for j in xrange(N):
            a, b = [int(x) for x in f.readline().split()]
            a_list.append(a)
            b_list.append(b)
        result = 0
        for j in xrange(N):
            for k in xrange(j+1, N):
                if a_list[j] < a_list[k] and b_list[j] > b_list[k]: result+=1
                if a_list[j] > a_list[k] and b_list[j] < b_list[k]: result+=1

        fout.write(''.join(('Case #', str(i+1), ': ', str(result), '\n')))
    fout.close()
    f.close()