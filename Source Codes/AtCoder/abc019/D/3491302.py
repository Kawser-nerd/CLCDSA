import sys
N = int(input())
mai, mad = 0, 0
for i in range(2, N + 1):
    print("? {0} {1}".format(1, i))
    sys.stdout.flush()
    d = int(input())
    if d > mad:
        mad = d
        mai = i

D = 0
for i in range(1, N + 1):
    if i == mai:
        continue
    print("? {0} {1}".format(mai, i))
    sys.stdout.flush()
    d = int(input())
    if d > D:
        D = d

print("! {}".format(D))