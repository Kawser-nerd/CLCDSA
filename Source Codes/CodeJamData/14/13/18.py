##input = open('C-sample-input.txt', 'r')
##output = open('C-sample-output.txt', 'w')

input = open('C-small-attempt0.in', 'r')
output = open('C-small.out', 'w')

##input = open('C-large.in', 'r')
##output = open('C-large.out', 'w')

def read_int():
    return int(input.readline().strip())

def read_ints():
    return [int(x) for x in input.readline().split()]

def read_float():
    return float(input.readline().strip())

def read_floats():
    return [float(x) for x in input.readline().split()]

def solve(N, perm):
    count = 0
    for i in range(N-1):
        if i < 600:
            if i < perm[i] and perm[i] - i <= 400:
                count += 1
        else:
            if i < perm[i]:
                count += 1
    if count >= 340:
        return "BAD"
    return "GOOD"

def main():
    num_cases = read_int()
    for case in range(1, num_cases+1):
        N = read_int()
        perm = read_ints()
##        if case == 1:        
        solution = solve(N, perm)
        solution_string = "Case #%d: %s" %(case, solution)
        output.write(solution_string + "\n")
        print solution_string
        

main()
input.close()
output.close()
    
