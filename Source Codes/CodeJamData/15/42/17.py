LINES_PARAM = 0
INPUT_FILE_NAME = 'B-large.in'
OUTPUT_FILE_NAME = 'B-large.out'

def do_case(parsed):
        heatNeeded=parsed[0][2]
        Vol=parsed[0][1]
        taps=sorted(parsed[1:], key=lambda x:x[1])
        heats=0
        vols=0
        hotter=False
        for tap in taps:
                heats+=tap[0]*tap[1]
                vols+=tap[0]
        if vols*heatNeeded>heats:
                taps=taps[::-1]
                hotter=True
        heats=0
        vols=0
        if (taps[0][1]>heatNeeded and not hotter)or(taps[0][1]<heatNeeded and hotter):
                return "IMPOSSIBLE"
        for tap in taps:
                if (heats+tap[1]*tap[0]<=heatNeeded*(vols+tap[0]) and not hotter) or (heats+tap[1]*tap[0]>=heatNeeded*(vols+tap[0]) and hotter):
                        vols+=tap[0]
                        heats+=tap[1]*tap[0]
                elif tap[1]==heatNeeded:
                        vols+=tap[0]
                        heats+=tap[1]*tap[0]
                else:
                        p=(heatNeeded*vols-heats)/(tap[1]*tap[0]-tap[0]*heatNeeded)
                        vols+=tap[0]*p
                        heats+=tap[1]*tap[0]*p
                        break
        result=Vol/vols
        return str(result)
def do_parse(input):
        return [[float(num) for num in line.rstrip().split(" ")]for line in input]       
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
