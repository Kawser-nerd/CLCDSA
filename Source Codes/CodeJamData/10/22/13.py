'''
Created on 22 May 2010

@author: Shahar
'''

def B(inpfile):
    fin = open(inpfile, 'r')
    fout = open(inpfile+'.out', 'w')
    CNT = int(fin.readline())
    for iCNT in range(CNT):
        numbers = map(int, fin.readline().rstrip('\n').split(' '))
        N = numbers[0]
        K = numbers[1]
        B = numbers[2]
        T = numbers[3]
        X = map(int, fin.readline().rstrip('\n').split(' '))
        V = map(int, fin.readline().rstrip('\n').split(' '))
        X.reverse()
        V.reverse()
        
        OnTime = 0
        Switches = 0
        Obstacles = 0
        for iN in xrange(N) :
            if B - X[iN] <= V[iN]*T :
                OnTime += 1
                Switches += Obstacles 
            else :
                Obstacles += 1
            
            if OnTime == K : 
                break 
        
        if (OnTime < K) :
            result = 'IMPOSSIBLE'
        else :
            result = str(Switches)
        
        text = 'Case #' + str(iCNT+1) + ': ' + result 
        print text
        fout.write(text + '\n')

if __name__ == "__main__":
    #B(sys.argv[1]);
    #B('..\\test\\B-test.in');
    #B('..\\test\\B-small-attempt0.in');
    #B('..\\test\\B-small-attempt1.in');
    B('..\\test\\B-large.in');
