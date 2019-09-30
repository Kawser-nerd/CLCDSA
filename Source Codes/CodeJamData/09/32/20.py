# Code Jam Round 1C - Prob B
# 13/9/2009

import random, math

def norm(x):
    return math.sqrt(sum([i*i for i in x]))

def dot(x, y):
    return [x[i]*y[i] for i in range(0, min(len(x), len(y)))]

def dot_sum(x, y):
    return sum(dot(x, y))

def dist_point_plane(plane, point):
    if plane == [0.0, 0.0, 0.0]:
        return norm(point)
    return dot_sum(plane, point)/norm(plane)       

inname = 'E:\B.in.txt'

fin = open(inname, 'r')
fout = open('E:\B.out.txt', 'w')

lines = fin.readlines()

cases = int(lines[0].strip())
pointer = 1

for case in range(1, cases + 1):
    fly_count = int(lines[pointer].strip())
    fly_info = []
#    fly_pos = []

    for i in range(0, fly_count):
        pointer += 1
        fly_info.append([int(x) for x in lines[pointer].strip().split()])
 #       fly_pos.append(fly_info[-1][:3])

    com_0 = [0, 0, 0]
    for fly in range(0, fly_count):
#        fly_pos[fly] = [fly_pos[fly][i] + fly_info[fly][i + 3] for i in range(0, 3)]
        com_0 = [com_0[i] + fly_info[fly][i] for i in range(0, 3)]
    com_0 = [com_0[i] / float(fly_count) for i in range(0, 3)]

#    print(com_0)
    
    com_speed = [0, 0, 0]
    for fly in range(0, fly_count):
        com_speed = [com_speed[i] + fly_info[fly][i + 3] for i in range(0, 3)]
    com_speed = [com_speed[i] / float(fly_count) for i in range(0, 3)]

    # need the distance from com_0 to the plane    
    dist = dist_point_plane(com_speed, com_0)
    time = 0
    if norm(com_speed) > 10e-7:
        time = -dist / norm(com_speed)

    time = max(0, time)
    closest_pos = norm([com_0[i] + time*com_speed[i] for i in [0, 1, 2]])
    if time < 10e-5:
        time = 0
    if closest_pos < 10e-5:
        closest_pos = 0

    fout.write('Case #' + str(case) + ': ' + str(closest_pos) + ' ' + str(time) + '\n')
    pointer += 1
        
fout.close()
fin.close()   
    
