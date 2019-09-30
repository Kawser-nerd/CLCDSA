raw_input()
n, M = [int(x) for x in raw_input().split()]

print "Case #1:"

for m in range(2**(n/2-1), 2**(n/2)):
    if M==0:
        break
    M -= 1
    s = bin(m)[2:]
    t = s+''.join(reversed(s))
    print t,
    for i in range(2, 11):
        print i+1,
    print
