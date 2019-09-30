def codejam(func):
    def jammed(*args, **kwargs):
        basepath = '/home/ilya/workspace/codejam-python/'
        inputname = basepath + 'input.txt'
        outputname = basepath + 'output.txt'
        f_in = open(inputname)
        f_out = open(outputname, 'w')
        ncases = int(f_in.readline().rstrip('\r\n'))
        
        for testcase in range(ncases):
            ans = func(f_in, *args, **kwargs)        
            f_out.write('Case #%i: ' % (testcase+1))
            f_out.write(str(ans))
            f_out.write('\n')
            print 'Case #%i:' % (testcase+1), ans
        
        f_out.close()
    return jammed

def read_int(f):
    return int(f.readline().rstrip('\r\n'))

def read_str(f):
    return f.readline().rstrip('\r\n')

def read_list(f):
    return map(int, f.readline().rstrip('\r\n').split(' '))

def list2str(l):
    return " ".join(map(str, l))