
# hardcoded solution for small input (yes, I'm an idiot)
# hope my calculator has enough precision

answers = ("001","005","027","143","751","935","607","903","991","335","047","943","471","055","447","463","991","095","607","263","151","855","527","743","351","135","407","903","791","135","647")

def Numbers():
    n = int(raw_input())
    print answers[n]

T = int(raw_input())
for testcase in range(T):
    print "Case #%d:" % (testcase + 1),
    Numbers()
