import sys
input = sys.stdin.readline
SE = []
N = int(input())
for i in range(N):
    S,E = map(int,input().split('-'))
    S = S - S % 5
    E = E + (5 - E) % 5
    if E % 100 == 60:
        E+=40
    SE.append([S,E])
SE.sort()
S,E=SE[0]
for s,e in SE:
    if E < s:
        print("{:0=4}".format(S)+"-"+"{:0=4}".format(E))
        S,E = s,e
    else:
        E = max(E,e)
print("{:0=4}".format(S)+"-"+"{:0=4}".format(E))