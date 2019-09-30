import math
n = int(input())

o = []
d = []

o_grav = [0, 0]
d_grav = [0, 0]
o_size_sqed = 0
d_size_sqed = 0

for i in range(0, n):
    buf = [int(n) for n in input().split(" ")]
    o_grav[0] += buf[0]
    o_grav[1] += buf[1]
    o.append(buf)

for i in range(0, n):
    buf = [int(n) for n in input().split(" ")]
    d_grav[0] += buf[0]
    d_grav[1] += buf[1]
    d.append(buf)

for no in o:
    o_size_sqed += (no[0] - o_grav[0]/n) ** 2 + (no[1] - o_grav[1]/n) ** 2

for nd in d:
    d_size_sqed += (nd[0] - d_grav[0]/n) ** 2 + (nd[1]  - d_grav[1]/n) ** 2

print(math.sqrt(d_size_sqed / o_size_sqed))