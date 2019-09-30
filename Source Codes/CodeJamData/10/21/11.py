#!/usr/bin/env python

import sys
content = file(sys.argv[1])
T = int(content.readline())
for i in range(T):
    nums = content.readline().split()
    existing = []
    new = []
    existing.append('/')
    for j in range(int(nums[0])):
        existing.append(content.readline().strip())
    for j in range(int(nums[1])):
        new.append(content.readline())
    tot = 0
    for item in new:
        liste = item.strip().split('/')
        liste = liste[1:]
        string = ""
        for val in liste:
            string +='/'
            string += val
#            print string
            done = 0
            for a in existing:
                if (string == a):
                    done=1
                    break
            if (done==0):
                existing.append(string)
                tot +=1
    print "Case #%d: %d" % (i+1,tot)
    
