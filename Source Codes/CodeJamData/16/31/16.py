import sys

def letter(x):
    return chr(ord('A') + x)

def solve_test(inp):
    n = int(inp.readline())
    ans = []
    counts = [int(x) for x in inp.readline().split()]
    total = sum(counts)
    if total % 2 == 1:
      winner = counts.index(max(counts))
      ans.append(letter(winner))
      counts[winner] -= 1
    while sum(counts) > 0:
      winner1 = counts.index(max(counts))
      counts[winner1] -= 1
      winner2 = counts.index(max(counts))
      counts[winner2] -= 1

      ans.append(letter(winner1)+ letter(winner2))
    return ' '.join(ans) 

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