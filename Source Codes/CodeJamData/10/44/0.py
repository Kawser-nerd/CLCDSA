import math

for i in xrange(1,1+int(raw_input())):
    [N,M] = [int(z) for z in raw_input().split()]
    [p1x,p1y] = [int(z) for z in raw_input().split()]
    [p2x,p2y] = [int(z) for z in raw_input().split()]
    answer = "Case #%d: " % i
    for j in xrange(M):
        [qx,qy] = [int(z) for z in raw_input().split()]
        r1 = math.sqrt(((p1x - qx) ** 2) + ((p1y - qy) ** 2))
        r2 = math.sqrt(((p2x - qx) ** 2) + ((p2y - qy) ** 2))
        dist = math.sqrt(((p1x - p2x) ** 2) + ((p1y - p2y) ** 2))
        cosAngle1 = ((r1 ** 2) + (dist ** 2) - (r2 ** 2)) / (2 * r1 * dist)
        Angle1 = math.acos(cosAngle1)
        doubleAngle1 = 2 * Angle1
        cosAngle2 = ((r2 ** 2) + (dist ** 2) - (r1 ** 2)) / (2 * r2 * dist)
        Angle2 = math.acos(cosAngle2)
        doubleAngle2 = 2 * Angle2
        doubleArea = r1 * r1 * (doubleAngle1 - math.sin(doubleAngle1)) + r2 * r2 * (doubleAngle2 - math.sin(doubleAngle2))
        answer += "%.8f " % (doubleArea/2)
    print answer
