
gcds = {}
def gcd(a, b):
    end = max(a,b)
    sor = min(a,b)
    if end in gcds:
        if sor in gcds[end]:
            return gcds[end][sor]
    rem = end % sor
    if rem == 0:
        if end not in gcds:
            gcds[end] = {}
        gcds[end][sor] = sor
        return sor
    else:
        answer = gcd(sor, rem) 
        if end not in gcds:
            gcds[end] = {}
        gcds[end][sor] = answer
        return answer

def solver(n, pd, pg):
    if pd == 0:
        if pg == 100:
            return "Broken"
        else:
            return "Possible"
    if pg == 0:
        if pd == 0:
            return "Possible"
        else:
            return "Broken"
    min_played = 100 / gcd(pd, 100)
    if min_played > n:
        return "Broken"
    if pg == 100 and not pd == 100:
        return "Broken"
    return "Possible"


def ssi(s):
    """
    space separated integers
    """
    return map(int, s.strip('\n').split())

def main():
    # open input file
    input_file = open('infile.txt')
    cases = int(input_file.readline())
    output = []
    # loop through cases passing input to solver
    for c in range(cases):
        [n, pd, pg] = ssi(input_file.readline())
        answer = solver(n, pd, pg)
        output.append('Case #%d: %s\n' % (c+1, str(answer)))
    input_file.close()
    # open output file
    output_file = open('outfile.txt', 'w')
    # write ouput to file
    output_file.writelines(output)
    # close out file
    output_file.close()
    print 'Done!'



if __name__=='__main__':
    main()
