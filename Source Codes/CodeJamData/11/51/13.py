import math

with open('input.in', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        for casenum in range(1, numcases+1):
            print(casenum)
            info = [int(i) for i in fin.readline().split()]
            lower = [[int(i) for i in fin.readline().split()] for j in range(info[1])]
            upper = [[int(i) for i in fin.readline().split()] for j in range(info[2])]
            
            start = upper[0][1] - lower[0][1]
            lowi = 1
            uppi = 1
            lowslope = float(lower[1][1]-lower[0][1])/(lower[1][0])
            uppslope = float(upper[1][1]-upper[0][1])/(upper[1][0])
            area = 0
            height = float(start)
            i=0
            while (i < info[0]):
                slope = uppslope - lowslope
                area += (height+slope/2)
                height += slope
                if (i < info[0] -1):
                    if (i == lower[lowi][0]-1):
                        lowi += 1
                        lowslope = float(lower[lowi][1]-lower[lowi-1][1])/(lower[lowi][0]-lower[lowi-1][0])
                    if (i == upper[uppi][0]-1):
                        uppi += 1
                        uppslope = float(upper[uppi][1]-upper[uppi-1][1])/(upper[uppi][0]-upper[uppi-1][0])
                i += 1
            i = 0
            height = float(start)
            lowi = 1
            uppi = 1
            lowslope = float(lower[1][1]-lower[0][1])/(lower[1][0])
            uppslope = float(upper[1][1]-upper[0][1])/(upper[1][0])
            totalarea = area
            solnstr = ""
            cut = 1
            nextpos = totalarea*(float(cut)/info[3])
            area = 0
            while (i < info[0]):
                slope = uppslope - lowslope
                oldarea = area
                area += (height+slope/2)
                while (area > nextpos):
                    
                    cutfrac = 0
                    remaining = nextpos - oldarea
                    if (slope == 0):
                        cutfrac = remaining/height
                    else:
                        
                        cutfrac = (-height +(height*height+2*slope*remaining)**.5)/slope
                    solnstr += "\n" + str(i+cutfrac)
                    cut += 1
                    nextpos = totalarea*(float(cut)/info[3])
                height += slope



                
                if (i < info[0] -1):
                    if (i == lower[lowi][0]-1):
                        lowi += 1
                        lowslope = float(lower[lowi][1]-lower[lowi-1][1])/(lower[lowi][0]-lower[lowi-1][0])
                    if (i == upper[uppi][0]-1):
                        uppi += 1
                        uppslope = float(upper[uppi][1]-upper[uppi-1][1])/(upper[uppi][0]-upper[uppi-1][0])
                i += 1









            

            fout.write("Case #"+str(casenum)+": "+solnstr+'\n')
