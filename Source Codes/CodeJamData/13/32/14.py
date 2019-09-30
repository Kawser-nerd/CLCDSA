import sys,os

class OutFile(file):
    def __init__(self,file_name):
        file.__init__(self,file_name,'w')
        self.console = sys.stdout
    def __enter__(self,*argv):
        sys.stdout = self
        return self
    def __exit__(self,*argv):
        sys.stdout = self.console
    def write(self,x):
        self.console.write(x)
        file.write(self,x)

class InFile(file):
    def get_int(self):
        return int(self.readline())
    def get_line_int(self):
        return map(int,self.get_line_str())
    def get_line_str(self):
        return self.readline().split()

def do_all(file_name):
    file_name1 = os.path.splitext(file_name)[0]+'.out'
    with InFile(file_name) as f1:
        with OutFile(file_name1) as f2:
            for i in xrange(1,f1.get_int()+1):
                print 'Case #%s:'%i,
                calculation(f1)

def count(x,y):
    i = 1
    c = 0
    L = [abs(y),abs(x)]
    while L:
        if L[-1] >= i:
            L[-1] -= i
            c+=1
            i+=1
        else:
            i+=L[-1]*2
            c+=L.pop()*2
    return c

def reach(start,length,direct):
    L = []
    while start <= length:
        length-=start
        start +=1
        L.append(direct[0])
    for i in xrange(length):
        L.append(direct[1])
        L.append(direct[0])
        start +=2
    return L,start

def calculation(f_in):
    X,Y = f_in.get_line_int()
    n1 = count(X,Y)
    n2 = count(Y,X)
    path = []
    directx = 'EW' if X>0 else 'WE'
    directy = 'NS' if Y>0 else 'SN'
    if n1<n2:
        subpath,start = reach(1,abs(X),directx)
        path.extend(subpath)
        subpath,end = reach(start,abs(Y),directy)
        path.extend(subpath)
    else:
        subpath,start = reach(1,abs(Y),directy)
        path.extend(subpath)
        subpath,end = reach(start,abs(X),directx)
        path.extend(subpath)
    print ''.join(path)

if __name__ == '__main__':
    do_all(sys.argv[1])
