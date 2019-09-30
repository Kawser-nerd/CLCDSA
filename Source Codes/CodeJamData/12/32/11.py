directory = 'C:/users/hai/my projects/google code jam/2012/1C/B/'

from math import sqrt
from fractions import Fraction

def strfloat_to_fraction (s):
    try:
        if s[0] == '-':
            s = s[1:]
            is_negative = True
        else:
            is_negative= False
        
        a = s.split('.')
        if len(a) == 1:
            return int(a[0])
        assert len(a)==2
        if a[1] == '':
            return int(a[0])
        
        if a[0] == '':
            first = 0
        else:
            first = int(a[0])
        f = first + Fraction(int(a[1]),10**len(a[1]))
        if is_negative:
            f = -f
        return f

    except:
        raise ValueError('could not convert string to Fraction: ' + repr(s))



def solve (f_in, f_out):
    T = int(f_in.readline())
    for testcase in range(1,T+1):
        line = f_in.readline().split()
        D = strfloat_to_fraction(line[0])
        N = int(line[1])
        f_out.write ('Case #' + str(testcase) + ':\n')
        
        if N == 2:
            t0, x0 = [strfloat_to_fraction(x) for x in f_in.readline().split()]
            t1, x1 = [strfloat_to_fraction(x) for x in f_in.readline().split()]
            accs = [strfloat_to_fraction(x) for x in f_in.readline().split()]
            assert t0 == 0
            assert x1 >= D
            assert x1 >= x0
            for a in accs:
                if x1 == x0 or x0 >=D:
                    assert x0 >=D
                    res = sqrt (2*D/a)
                else:
                    velocity = (x1-x0)/t1
                    t_end = (D-x0)/velocity
                    #print (testcase, float(t0),float(x0),float(t1),float(x1),float(D),float(a))
                    if D <= a*t_end**2/2:
                        res = float(t_end)
                    else:
                        res = sqrt (2*D/a)
                    #print (res)
                f_out.write(str(res) + '\n')
                
        else:
            assert N==1
            t0, x0 = [strfloat_to_fraction(x) for x in f_in.readline().split()]
            accs = [strfloat_to_fraction(x) for x in f_in.readline().split()]
            assert t0 == 0
            assert x0 >= D
            for a in accs:
                #print (testcase, float(t0),float(x0),float(D),float(a))
                res = sqrt (2*D/a)
                #print (res)
                f_out.write(str(res) + '\n')
            

        print ()

        








def main_run():
    import os
    import time
    filenames = [x for x in os.listdir (directory)]
    filenames = [x for x in filenames if x.endswith('.in')]
    l1 = [(os.stat(directory+x).st_ctime, x) for x in filenames]
    chosen_filename =  sorted(l1)[-1][1][:-3]

    print ('Directory : ', directory)
    print ('Chosen Filename : ',chosen_filename)
    print()
    print ('Start : ', time.ctime())
    print()
    
    f_in = open(directory+chosen_filename+'.in')
    f_out = open(directory+chosen_filename+'.out', 'w')
    solve(f_in,f_out)
    f_in.close()
    f_out.close()

    print ()
    print ('End : ', time.ctime())


main_run()


