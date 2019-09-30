LINES_FOR_EACH_INPUT = 2
INPUT_FILE_NAME = 'A-large.in'
OUTPUT_FILE_NAME = 'A-large.out'

def rem2(rems):
    return rems[0]+(rems[1]+1)//2
def rem3(rems):
    return rems[0]+min(rems[1],rems[2])+(max(rems[1],rems[2])-min(rems[1],rems[2])+2)//3
def rem4(rems):
    s=rems[0]
    s+=rems[2]//2
    rems[2]%=2
    a=min(rems[1],rems[3])
    s+=a
    b=max(rems[1],rems[3])-a
    if rems[2]>0:
        if b<=2:
            return s+1
        else:
            s+=1
            b-=2
    return s+(b+3)//4
def do_case(parsed):
    p=parsed[0][1]
    rems=[0 for i in range(p)]
    for g in parsed[1]:
        rems[g%p]+=1
    fresh={
        2:rem2,
        3:rem3,
        4:rem4
    }
    return str(fresh[p](rems))



def do_parse(input):
     return [[int(num) for num in line.rstrip().split(" ")]for line in input]


def main():
    input_f = open(INPUT_FILE_NAME, 'r')
    output = []

    num_of_test_cases = int(input_f.readline(), 10)

    input_lines = input_f.readlines()

    for test_case in range(num_of_test_cases):
        parsed_input = do_parse(input_lines[test_case * LINES_FOR_EACH_INPUT: (test_case + 1) * LINES_FOR_EACH_INPUT])
        output.append('Case #' + str(test_case + 1) + ': ' + do_case(parsed_input))

    output_f = open(OUTPUT_FILE_NAME, 'w')
    output_f.write('\n'.join(output))

    input_f.close()
    output_f.close()


if __name__ == '__main__':
    main()
