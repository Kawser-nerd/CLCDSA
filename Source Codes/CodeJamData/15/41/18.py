LINES_PARAM = 0
INPUT_FILE_NAME = 'A-large.in'
OUTPUT_FILE_NAME = 'A-large.out'

def do_case(parsed):
        result=0
        for i in range(len(parsed)):
                for j in range(len(parsed[0])):
                        if parsed[i][j]!=".":
                                up=False
                                down=False
                                right=False
                                left=False
                                for k in range(i):
                                        if parsed[k][j]!=".":
                                                up=True
                                for k in range(i+1,len(parsed)):
                                        if parsed[k][j]!=".":
                                                down=True
                                for k in range(j):
                                        if parsed[i][k]!=".":
                                                left=True
                                for k in range(j+1,len(parsed[0])):
                                        if parsed[i][k]!=".":
                                                right=True
                                if not up and not down and not left and not right:
                                        return "IMPOSSIBLE"
                                elif (parsed[i][j]=="v" and not down) or (parsed[i][j]=="^" and not up)or (parsed[i][j]==">" and not right) or (parsed[i][j]=="<" and not left):
                                        result+=1
        return str(result)

def do_parse(input):
        return [list(line.rstrip()) for line in input[1:]]
def main():
        input_f = open(INPUT_FILE_NAME, 'r')
        output = []
	
        num_of_test_cases = int(input_f.readline(), 10)
        temp=input_f.readlines()
        index=0
        for test_case in range(num_of_test_cases):
                lines=int(temp[index].rstrip().split(" ")[LINES_PARAM])
                parsed_input = do_parse(temp[index:index+lines+1])
                index=index+1+lines
                output.append('Case #' + str(test_case + 1) + ': ' + do_case(parsed_input))

        output_f = open(OUTPUT_FILE_NAME, 'w')
        output_f.write('\n'.join(output))
	
        input_f.close()
        output_f.close()
	
if __name__ == '__main__':
        main()
