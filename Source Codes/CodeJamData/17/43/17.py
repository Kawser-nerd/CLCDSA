LINES_PARAM = 0
INPUT_FILE_NAME = 'C-small-attempt4.in'
OUTPUT_FILE_NAME = 'C-small-attempt4.out'
def findhor(a,i):
    seen=False
    k=i
    vis = True
    for j in range(i + 1, len(a)):
        if (a[j] == '|' or a[j] == '-') and vis:
            if seen:
                return i
            k=j
            seen=True
        if a[j] == '#':
            vis = False
    vis = True
    for j in range(i - 1, -1, -1):
        if (a[j] == '|' or a[j] == '-') and vis:
            if seen:
                return i
            k = j
            seen=True
        if a[j] == '#':
            vis = False
    return k
def seesVert(a,i):
    vis = True
    for j in range(i+1,len(a)):
        if (a[j]=='|') and vis:
            return True
        if a[j]=='#':
            vis=False
    vis=True
    for j in range(i-1,-1,-1):
        if (a[j]=='|') and vis:
            return True
        if a[j]=='#':
            vis=False
    return False
def seesBeam(a,i):
    vis = True
    for j in range(i+1,len(a)):
        if (a[j]=='|' or a[j]=='-') and vis:
            return True
        if a[j]=='#':
            vis=False
    vis=True
    for j in range(i-1,-1,-1):
        if (a[j]=='|' or a[j]=='-') and vis:
            return True
        if a[j]=='#':
            vis=False
    return False
def do_case(parsed):
    R=int(parsed[0][0])
    C=int(parsed[0][1])
    parsed=[[parsed[i][0][j] for j in range(C)] for i in range(1,R+1)]
    for i in range(R):
        for j in range(C):
            if parsed[i][j]=='-':
                parsed[i][j]='|'
    for i in range(R):
        for j in range(C):
            if parsed[i][j]=='|':
                samecol=seesBeam([parsed[k][j] for k in range(R)],i)
                if samecol:
                    if seesBeam(parsed[i],j):
                        return 'IMPOSSIBLE'
                    parsed[i][j]='-'
    for t in range(5*C+5*R):
        for i in range(R):
            for j in range(C):
                if parsed[i][j]=='.':
                    samecol=seesVert([parsed[k][j] for k in range(R)],i)
                    if not samecol:
                        k=findhor(parsed[i],j)
                        if k==j:
                            return 'IMPOSSIBLE'
                        parsed[i][k]='-'
    lines=[''.join(parsed[i]) for i in range(R)]
    return '\n'.join(['POSSIBLE','\n'.join(lines)])


def do_parse(input):
    return [line.rstrip().split(" ") for line in input]


def main():
    input_f = open(INPUT_FILE_NAME, 'r')
    output = []

    num_of_test_cases = int(input_f.readline(), 10)
    temp = input_f.readlines()
    index = 0
    for test_case in range(num_of_test_cases):
        lines = int(temp[index].rstrip().split(" ")[LINES_PARAM])
        parsed_input = do_parse(temp[index:index + lines + 1])
        index = index + 1 + lines
        output.append('Case #' + str(test_case + 1) + ': ' + do_case(parsed_input))

    output_f = open(OUTPUT_FILE_NAME, 'w')
    output_f.write('\n'.join(output))

    input_f.close()
    output_f.close()


if __name__ == '__main__':
    main()
