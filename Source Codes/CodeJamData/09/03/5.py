text = [line.strip("\n") for line in open("C.in","rt").readlines()]
outfile = open("C.out","wt")

MOD = 10000
searched_string = "welcome to code jam"

'''
Vegeta, what does the scouter say about his string level?
IT'S...ONLY FIVE HUNDREEEEEEED!!!!
What, 500? There's no way that can be right!

(Cause there's no way I won't even have to use an index tree!)
'''

'''
OH WOW!
My solution for the small dataset was actually wrong!
(It didn't to the whole "modulo" thing properly)
'''

tests = int(text[0])
offset = 1
for test in range(1, tests+1):
    line = text[offset]
    print line
    line = "#" + line
    found = {}
    for x in range(len(line)):
        found[x] = [0] * (len(searched_string) + 1)
        if x == 0:
            found[x][0] = 1
        for found_idx in range(0, len(searched_string)):
            if line[x] == searched_string[found_idx]:
                for y in range(x):
                    found[x][found_idx+1] += found[y][found_idx]
                    '''
                    Haha, poor CPP.
                    They don't even have proper bignum support :)
                    '''
                    found[x][found_idx+1] %= MOD
    ans = str((sum(line[-1] for line in found.values())) % MOD)
    ans = "0" * (4 - len(ans)) + ans
    assert(len(ans) == 4)
    print "Case #%s: %s" % (test, ans)
    outfile.write("Case #%s: %s\n" % (test, ans))
    offset += 1

