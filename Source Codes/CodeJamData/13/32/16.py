from collections import Counter

def solve(x, y):

    directions = []

    if x > 0:
        for i in range(x):
            directions.append('WE')
    elif x < 0:
        for i in range(-x):
            directions.append('EW')
    if y > 0:
        for i in range(y):
            directions.append('SN') 
    elif y < 0:
        for i in range(-y):
            directions.append('NS') 
                
    return ''.join(directions)

if __name__ == '__main__':

    import sys
    
    input_file = sys.argv[1]
    output_file = input_file[:].replace('.in', '.out')


    f_in = open(input_file, 'r')
    f_out = open(output_file, 'w')

    T, = [int(x) for x in f_in.readline().split()]

    for case in range(1, T+1):
        print 
        print '====================='
        print '    ' + str(case)
        print '====================='

        x, y = [int(i) for i in f_in.readline().split()]

        # Solve
        ans = solve(x, y)
        print ans

        ## Output
        f_out.write('Case #%d: %s\n' % (case, ans))

        

