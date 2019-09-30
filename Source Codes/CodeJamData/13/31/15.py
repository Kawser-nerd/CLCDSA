from collections import Counter

vowels = ['a', 'e', 'i', 'o', 'u']


def solve(s, n):

    total = 0
    is_first = True
    cont = 0

    arr = [0 for i in range(len(s))]

    if s[0] not in vowels:
        cont = 1
        if n == 1:
            is_first = False
            last_cont = 0
            arr[0] = 1

    for i in range(1, len(s)):
        #print s[i], cont, arr
        if s[i] in vowels: 
            cont = 0
            arr[i] = arr[i-1]
        else:
            cont += 1
            if  cont < n:
                arr[i] = arr[i-1]
            elif cont == n:
                if is_first:
                    is_first = False
                    arr[i] = i + 2 - n
                    last_cont = i
                    
                else:
                    arr[i] = i - last_cont + arr[i-1]
                    last_cont = i
                    
            elif cont > n:
                arr[i] = arr[i-1] + 1
                last_cont = i

            else: raise Exception('wo')
                
    print arr
    return sum(arr)

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

        s, n = [x for x in f_in.readline().split()]
        n = int(n)


        # Solve
        ans = solve(s, n)

        print ans

        ## Output
        f_out.write('Case #%d: %s\n' % (case, ans))

        

