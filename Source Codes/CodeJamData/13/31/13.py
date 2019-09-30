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

def calculation(f_in):
    string,n = f_in.get_line_str()
    n = int(n)
    count = 0
    before = 0
    total = 0
    vowel = 'aeiou'
    for i,s in enumerate(string):
        if s in vowel:
            count = 0
            total += before
        else:
            count+=1
            if count >= n:
                before = i-n+2
            total += before
    print total

if __name__ == '__main__':
    do_all(sys.argv[1])
