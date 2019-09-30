#!/usr/bin/env python


class wind():
    def __init__(self,left,right):
        self.left = left
        self.right = right

def comp(x,y):
    if x.left < y.left:
        return -1
    elif x.left > y.left:
        return 1
    else:
        return 0

def main():
    fin = open('large.in','r')
    fout = open('large.out','w')
    tn = int(fin.readline())
    for test in range(tn):
        n = int(fin.readline())
        building = []
        for i in range(n):
            left,right = fin.readline().split(' ')
            left = int(left)
            right = int(right)
            building.append(wind(left,right))
        building.sort(comp)
        ans = 0
        for i in range(n):
            for j in range(i+1,n):
                if (building[i].right > building[j].right):
                    ans += 1
        for floor in building:
            print floor.left,' ',floor.right
        fout.write('Case #%d: %d\n' % (test+1,ans))
        print '---------------'

    fin.close()
    fout.close()

if __name__=='__main__':
    main()
