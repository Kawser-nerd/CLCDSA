import numpy as np
LINES_PARAM = 2
INPUT_FILE_NAME = 'B-large.in'
OUTPUT_FILE_NAME = 'B-large.out'


def do_case(parsed):
    n=parsed[0][0]
    c=parsed[0][1]
    seat=[0 for i in range(n)]
    rider=[0 for i in range(c)]
    for l in parsed[1:]:
        rider[l[1]-1]+=1
        seat[l[0]-1]+=1
    s=np.cumsum(seat)
    m=max(rider)
    for i in range(n):
        m=max(m,(s[i]+i)//(i+1))
    pr=sum([max(0,se-m) for se in seat])
    return str(m)+' '+str(pr)


def do_parse(input):
    return [[int(num) for num in line.rstrip().split(" ")] for line in input]


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
