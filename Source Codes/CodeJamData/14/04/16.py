def cheat(naomi, ken):
    nscore = 0

    naomi.sort()
    ken.sort()

    while len(naomi) > 0:
        while  len(ken) >0 and (ken[-1] > naomi[-1] or naomi[0] < ken[0]):

            if ken[-1] > naomi[-1]:
                ken.pop()
                naomi.pop(0)
                #print "+1 for ken"


            if len(ken) >0 and naomi[0] < ken[0]:
                naomi.pop(0)
                ken.pop()
                #print "+1 for ken (type2)"

        if len(ken) >0 and max(naomi) > max(ken): #should be!
            naomi.pop()
            ken.pop()
            #print "+1 for naomi"
            nscore +=1 



    return nscore

def fair(naomi,ken):

    nscore = 0

    naomi.sort()
    ken.sort()

    while len(naomi) > 0:
        nplay = naomi.pop(0)
        #print nplay
        for x in range(len(ken)):
            if ken[x] > nplay:
                ken.pop(x)
                break
        if len(ken) != len(naomi):
            ken.pop(0)
            nscore +=1

            #print naomi, ken

    return nscore


f = open('input.in', 'r')
data = f.read().split('\n')
#print data

length = int(data[0])
for x in range(length):
    naomi = map(float, data[2 + 3*x].split(" "))
    ken = map(float, data[3+ 3*x].split(" "))
    n,k = list(naomi), list(ken)
    print "Case #%d: %d %d" % (x+1, cheat(n,k) , fair(naomi,ken))
