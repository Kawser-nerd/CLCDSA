import sys

def solve_test(inp):
    B, M = map(int, inp.readline().split())
    if M > 2 ** (B-2):
      return 'IMPOSSIBLE'
    if M == 2 ** (B-2):
      first = '0' + '1' * (B-1)
    else:
      first = '0' + bin(M)[2:].zfill(B-2) + '0'
    print(bin(M), bin(M)[2:].zfill(B-2))
    lines = ['0' * i + '1' * (B-i) for i in range(2,B+1)]
    return 'POSSIBLE\n' + '\n'.join([first]+lines)


def solve_dumb(inp):
    return '1'

inp = open(sys.argv[1])
inp_dumb = open(sys.argv[1])
out = open(sys.argv[1].rsplit('.',1)[0]+'.out', 'w')
out_dumb = open(sys.argv[1].rsplit('.',1)[0]+'.dumb.out', 'w')
n_tests = int(inp.readline())
for i in range(n_tests):
    ans = solve_test(inp)
    print("Case #%d: " % (i+1) + ans, file=out)

#
    ans_dumb = solve_dumb(inp_dumb)
    print("Case #%d: " % (i+1) + ans_dumb, file=out_dumb)

    if ans != ans_dumb:
      print('Wrong', i+1, file=sys.stderr)
#
out.close()