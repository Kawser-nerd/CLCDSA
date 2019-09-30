import sys
fin = sys.stdin.readline

N, Z, W = [int(elem) for elem in fin().split()]
a_list = [int(elem) for elem in fin().split()]
assert len(a_list) == N

if N == 1:
    print(abs(a_list[-1] - W))
else:
    print(max(abs(a_list[-1] - W), abs(a_list[-2] - a_list[-1])))