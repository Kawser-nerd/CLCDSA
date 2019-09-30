hum,leg=map(int,input().split())

#c,m,o
if leg%2==0:
    o=0
else:
    o=1
    hum-=1
    leg-=3

#hum=c+m
#m=hum-c
#leg=4*c+2*m
#leg=4*c+2*(hum-c)
#leg=2*hum+2*c
c=int((leg-2*hum)/2)
m=int(hum-c)

if m<0 or c<0:
    print('-1 -1 -1')
else:
    print('{} {} {}'.format(m,o,c))