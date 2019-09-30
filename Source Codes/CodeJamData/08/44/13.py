import sys
def readline():
    return sys.stdin.readline()

def permutation(seq):
    n = len(seq)
    if n == 1:
        yield seq
    else:
        for i in range(n):
            seqi = [seq[i]]
            for x in permutation(seq[:i] + seq[i+1:]):
                yield seqi + x
def main():

    ncase = int(readline())
    for case in range(ncase):
        k = int(readline())
        s = readline().strip()

        ans = len(s)
        for p in permutation(range(k)):
            result = ''
            for i in range(0, len(s), k):
                for j in range(k):
                    result += s[i + p[j]]

            count = 0
            for i in range(len(s)):
                if i == 0 or result[i] != result[i-1]:
                    count += 1

            

            #print p, result, count

            ans = min(ans, count)


        print 'Case #%d: %d' % (case+1, ans)

main()
