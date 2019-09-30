import string

S = 0
N = 0
Q = 0
engine = {}
input_f = None
output_f = None

def case_init():
    global S, N, Q, engine, input_f, output_f
    S = string.atoi(input_f.readline())
    engine = {}
    for i in xrange(S):
        engine[input_f.readline()] = i
    Q = string.atoi(input_f.readline())

def query():
    global S, N, Q, engine, input_f, output_f
    for i in xrange(Q):
        yield engine[input_f.readline()]

def cal():
    global S, N, Q, engine, input_f, output_f
    result = [0] * S
    for i in query():
        for j in xrange(S):
            result[j] = min ( result[j], result[i]+1 )
        result[i] = 10000000

    return min(result)

def main():
    global S, N, Q, engine, input_f, output_f
    input_f = open('A-large.in','rb')
    output_f = open('output.txt','w')
    output_f.seek(0)
    N = string.atoi(input_f.readline())
    for i in xrange (N):
        case_init()
        output_f.write('Case #%d: %d\n' % ( i+1 , cal()))
    output_f.flush()

main()
