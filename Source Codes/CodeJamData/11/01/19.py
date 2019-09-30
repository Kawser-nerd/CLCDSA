#!/usr/bin/env python
import sys

def cal(seq):
    pos={'B':1, 'O':1}
    robot, button = seq[0]
    preRobot = robot
    time = button-pos[robot]+1
    preTime = time
    totalTime = time
    pos[robot]=button
    for robot, button in seq[1:]:
        time = abs(button-pos[robot])+1
        print robot, time, preTime, totalTime
        if robot!=preRobot:
            if time>preTime:
                time -= preTime
                totalTime += time
                preTime = time
            else:
                totalTime += 1
                preTime = 1
        else:
            preTime += time
            totalTime += time
        preRobot = robot
        pos[robot]=button
    return totalTime

def wf(fileName,results):
    f = open(fileName,'w')
    for i,r in enumerate(results):
        f.write('Case #%d: %s\n'%(i+1,r))
    f.close()

def rf(fileName):
    f = open(fileName,'r')
    inputs = []
    n = int(f.readline())
    for i in range(n):
        l = f.readline()
        inputs.append(l)
    return inputs
   
if __name__=='__main__':
    inputs = rf(sys.argv[-1])
    #inputs = ['2 B 2 B 1']
    #inputs = ['3 O 5 O 8 B 100']
    #inputs = ['4 O 2 B 1 B 2 O 4']
    #inputs = ['8 O 87 B 45 B 44 O 85 O 52 O 8 B 53 B 25']

    results = []
    for ip in inputs:
        ip = ip.split()
        c = int(ip[0])
        seq = []
        for i in range(c):
            seq.append((ip[1+2*i], int(ip[1+2*i+1])))
        print seq
        rt = cal(seq)
        print rt 
        if rt:
            results.append(str(rt))
        else:
            results.append('OFF')
    wf(sys.argv[-1][:-2]+'out',results)

