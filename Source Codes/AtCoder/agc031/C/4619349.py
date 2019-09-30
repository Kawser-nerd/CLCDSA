import sys
DBG = not True
DBG2 = not True
n,a,b =      map(int, input().split())
MAXM =  18
r = [0] * MAXM
s = [0] * MAXM
r[0] = [0]
r[1] = [0,1]
s[1] = [0,1]
p1a = [0,1,3,2]
p2a = [3,1,0,2,2,0,1,3]

def swiz(n,z,d):
    xpos = n - len(d)
    ypos = 0
    t = 0
    for i in range(n):
        if DBG2:
            print("sw lp i {} xp {} yp {} t {}".\
               format(i,xpos,ypos,t))
        if i in d:
            t += ((z >> xpos) & 1) << i
            xpos += 1
        else:
            t += ((z >> ypos) & 1) << i
            ypos += 1
    if  DBG2:
        print("sw z {} d {} ret {}".format(z,d,t))
    return t

for m in range(3,MAXM,2):
    s[m] = [0] * (2**m)
    for i in range(2**(m-2)):
        hi = s[m-2][i] << 2
        for j in range(4):
          s[m][4*i+j] = hi + \
            (p1a[j] if i == 0 else p2a[4*(i%2)+j])
          if DBG2:
              print("set s m {} i {} j {} - {}".\
                 format(m,i,j,s[m][4*i+j]))

for m in range(2,MAXM):
    r[m] = [0] * (2**m)
    for i in range(2**(m-1)):
        r[m][i  ] = r[m-1][i]
        r[m][2**m-1-i] = 2**(m-1) + r[m-1][i]

if DBG:
    for m in range(1,6):
        print(s[m])
    print("")
    for m in range(1,6):
        print(r[m])

z = a ^ b
cnt = 0
d = []
for i in range(MAXM):
    if z & (1<<i) != 0:
        cnt += 1
        d.append(i)
if cnt%2 == 0:
    print('NO')
    sys.exit(0)
else:
    print('YES')

sz = len(d)
if DBG:
    print("n {} a {} b {} sz {} d:".format(n,a,b,sz))
    print(d)

for i in range(2**sz):
    for j in range(2**(n-sz)):
        hi = (s[sz][i] << (n-sz))
        lo =  r[n-sz][j] if i%2 == 0 \
                         else r[n-sz][2**(n-sz)-1-j]
        z =  hi + lo
        sw = swiz(n,z,d)
        if DBG:
          print("i {} j {} hi {} lo {} z {} sw {}".\
               format(i,j,hi,lo,z,sw))
        sys.stdout.write(str(a^sw) + ' ')
print('')