##input = open('A-sample-input.txt', 'r')
##output = open('A-sample-output.txt', 'w')

##input = open('A-small-attempt0.in', 'r')
##output = open('A-small.out', 'w')

input = open('A-large.in', 'r')
output = open('A-large.out', 'w')

def read_int():
    return int(input.readline().strip())

def read_ints():
    return [int(x) for x in input.readline().split()]

def read_float():
    return float(input.readline().strip())

def read_floats():
    return [float(x) for x in input.readline().split()]

def bintoint(x):
    total = 0
    power = 0
    while len(x) > 0:
        total += 2 ** power * int(x[-1])
        power += 1
        x = x[:-1]
    return total


def solve(N, L, flow_in, flow_out):
    def solve_rec(xor_val, inflow, outflow):
        if len(inflow) == 0:
            return True
        for y in range(len(inflow)):
            if inflow[0] ^ outflow[y] == xor_val:
                new_outflow = outflow[:y] + outflow[y+1:]
                return solve_rec(xor_val, inflow[1:], new_outflow)
        return False
    
    flow_in = [bintoint(x) for x in flow_in]
    flow_out = [bintoint(x) for x in flow_out]
    for i in range(1):
        min_switches = -1
        for j in range(N):
            xor_val = flow_in[i] ^ flow_out[j]
            new_flow_in = flow_in[:i] + flow_in[i+1:]
            new_flow_out = flow_out[:j] + flow_out[j+1:]
            if solve_rec(xor_val, new_flow_in, new_flow_out):
                switches = bin(xor_val)[2:].count('1')
                if min_switches == -1 or switches < min_switches:
                    min_switches = switches
                
    if min_switches == -1:
        return "NOT POSSIBLE"
    return str(min_switches)

def main():
    num_cases = read_int()
    for case in range(1, num_cases+1):
        N, L = read_ints()
        flow_in = input.readline().split()
        flow_out = input.readline().split()
##        if case == 1:
        solution = solve(N, L, flow_in, flow_out)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
