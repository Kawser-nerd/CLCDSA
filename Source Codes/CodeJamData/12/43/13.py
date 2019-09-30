import random
def check(heights,hf):
    for i in range(len(hf)):
        for j in range(i+1,len(hf)+1):
            akt = hf[i]-1
            if j!=akt:
                x1 = j-i
                y1 = heights[j]-heights[i]
                x2 = akt-i
                y2 = heights[akt]-heights[i]
                if x1*y2-x2*y1 <=0 :
                    return False
    return True
def generate(n):
    return [random.randint(0,400) for i in range(n)]
t = int(raw_input())

for tt in range(1,t+1):
    n = int(raw_input())
    line = raw_input()
    highest_from = [int(i) for i in line.strip().split()]
    w = False
    for i in range(n-1):
        for j in range(i+1,highest_from[i]-1):
            if highest_from[j] > highest_from[i]:
                w=True
    if w:
        print "Case #{}: Impossible".format(tt)
    else:
        w = False
        heights = []
        while not w:
            heights = generate(n)
            w = check(heights,highest_from)
        res = "Case #{}: ".format(tt)
        for i in heights:
            res+=str(i)+" "
        print res
